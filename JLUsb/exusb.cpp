#include "exusb.h"

ExUSB::ExUSB()
{
    // creating a object space;
    ExUSBDevice = new CCyUSBDevice(NULL);

    if (ExUSBDevice->DeviceCount() <= 0)
    {
        // No Devices
        return;
    }
    // initilize once
    if (ExUSBDevice->Open(0))
    {
        deviceFlag = true;
        // Get endPoints
        int EPNumbers = ExUSBDevice->EndPointCount();
        CCyUSBEndPoint **lUSBEP = ExUSBDevice->EndPoints;
        for (int i = 0; i < EPNumbers; i++)
        {
            if (lUSBEP[i]->Attributes == 1)        //Isoc
            {
                if (lUSBEP[i]->bIn)
                {
                    ExUSBIsocInEP = ExUSBDevice->IsocInEndPt;
                }
                else
                {
                    ExUSBIsocOutEP = ExUSBDevice->IsocOutEndPt;
                }
            }
            else if (lUSBEP[i]->Attributes == 2)       // Bluk
            {
                if (lUSBEP[i]->bIn)
                {
                    ExUSBBlukInEP = ExUSBDevice->BulkInEndPt;
                }
                else
                {
                    ExUSBBlukOutEP = ExUSBDevice->BulkOutEndPt;
                }
            }
        } // end of for (int i = 0; i < EPNumbers; i++)
    } //if (ExUSBDevice->Open(0))
} //end of ExUSB::ExUSB()


ExUSB::~ExUSB()
{
    if (ExUSBDevice->DeviceCount() > 0)
    {
        ExUSBDevice->Close();
        delete(ExUSBDevice);
    }
}
// get USB InBulk Data
void ExUSB::GetBlockData(UCHAR *data,int *size)
{
    PUCHAR ubuf = (PUCHAR)malloc(512);
    memset(ubuf,0,512);
    CCyIsoPktInfo *pktInfos = new CCyIsoPktInfo();
    LONG b = 512;

    if (deviceFlag)
    {
        if (ExUSBBlukInEP->XferData(ubuf,b,pktInfos,true))
        {
            *size = (int)b;
            memcpy(data,ubuf,(int)b);
        }
        else
        {
            *size = 0;
        }
    }
    free(ubuf);
}

QImage *ExUSB::ExUSBShow()
{
    QImage *img = new QImage;
    PUCHAR ubuf = (PUCHAR)malloc(512);
    CCyIsoPktInfo *pktInfos = new CCyIsoPktInfo();

    int a;
    LONG b = 11;

    PUCHAR bur = (PUCHAR)malloc(10);

    for (int i= 0; i < 10; i++)
    {
        bur[i] = i;
    }
    if (ExUSBBlukOutEP->XferData(bur,b))
    {
        b = 512;
        if (ExUSBBlukInEP->XferData(ubuf,b,pktInfos,true))
        {
        //if (ExUSBBlukInEP->XferData())
            UCHAR bbuf[b] = {0};
            a = 1;
            UCHAR t = ubuf[4];
            for (int i = 0; i < b; i++)
            {
                bbuf[i]= ubuf[i];
            }
            if (t > 0)
                t = 2;
        }
        else
        {
             a = 2;
        }
    }
    //OVERLAPPED * overla = new OVERLAPPED;
    //ExUSBBlukInEP->BeginDataXfer(ubuf,512,overla);

    free(ubuf);
    return img;

} // QImage ExUSB::ExUSBShow()
void ExUSB::WriteIIC(QString FileName)
{
    char* filename;
    QByteArray name = FileName.toLatin1();
    filename=name.data();
    CCyFX3Device *lfxdev = (CCyFX3Device*)ExUSBDevice;

    FX3_FWDWNLOAD_ERROR_CODE a = lfxdev->DownloadFw(filename,I2CE2PROM);
    if (a > 0)
        int b = 10;
}

bool ExUSB::GetUSBDeviceOnFlag()
{
    return deviceFlag;
}

// QThread for detecte/remove devices
void ExUSB::run()
{
    while(true)
    {
        UCHAR ldevcount= ExUSBDevice->DeviceCount();
        if (!deviceFlag)
        {
            if (ldevcount > 0)
            {
                if (ExUSBDevice->Open(0))
                {
                    deviceFlag = true;
                    // Get endPoints
                    int EPNumbers = ExUSBDevice->EndPointCount();
                    CCyUSBEndPoint **lUSBEP = ExUSBDevice->EndPoints;
                    for (int i = 0; i < EPNumbers; i++)
                    {
                        if (lUSBEP[i]->Attributes == 1)        //Isoc
                        {
                            if (lUSBEP[i]->bIn)
                            {
                                ExUSBIsocInEP = ExUSBDevice->IsocInEndPt;
                            }
                            else
                            {
                                ExUSBIsocOutEP = ExUSBDevice->IsocOutEndPt;
                            }
                        }
                        else if (lUSBEP[i]->Attributes == 2)       // Bluk
                        {
                            if (lUSBEP[i]->bIn)
                            {
                                ExUSBBlukInEP = ExUSBDevice->BulkInEndPt;
                            }
                            else
                            {
                                ExUSBBlukOutEP = ExUSBDevice->BulkOutEndPt;
                            }
                        }
                    } // end of for (int i = 0; i < EPNumbers; i++)
                } //if (ExUSBDevice->Open(0))
            } // if (ldevcount > 0)
        }
        else
        {
            if (ldevcount == 0)
            {
                deviceFlag = false;
                ExUSBDevice->Close();
            }
            else
            {
                deviceFlag=true;
            }
        }
    } //while(true)
}
int ExUSB::JLProtocolCmd(QString cmd,QString data)
{
    PUCHAR send_buf = (PUCHAR)malloc(266);
    LONG send_size = 0;
    int retsize = 0;
    int i;

    if (deviceFlag)
    {
        //head
        QByteArray lcmd = cmd.toLocal8Bit();
        for (i = 0; i < lcmd.length();i++)
        {
            send_buf[i] = (UCHAR)lcmd.data()[1];
        }
        send_buf[2] = 0xff;
        QByteArray ldata = data.toLatin1();
        // length
        send_buf[3] = ((ldata.length()>>16)&0xff);
        send_buf[4] = ((ldata.length()>>8)&0xff);
        send_buf[5] = ((ldata.length()>>0)&0xff);
        // data
        for (i = 0;i < ldata.length();i++)
        {
            send_buf[i+6] = (UCHAR)ldata.data()[1];
        }
        // tail
        send_buf[i+6] = 0xff;
        send_buf[i+7] = 0xff;
        send_buf[i+8] = 0xff;
        send_buf[i+9] = 0x88;


        // send data
        send_size = (LONG)(i+9);
        retsize =  ExUSBBlukOutEP->XferData(send_buf,send_size);
    }
    free(send_buf);
    return retsize;
}
