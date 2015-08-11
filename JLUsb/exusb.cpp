#include "exusb.h"

ExUSB::ExUSB()
{
    // creating a object space;
    ExUSBDevice = new CCyUSBDevice(NULL);

    if (ExUSBDevice->DeviceCount() <= 0)
        return;
    ExUSBDevice->Open(0);
    int EPNumbers = ExUSBDevice->EndPointCount();

    CCyUSBEndPoint **lUSBEP = ExUSBDevice->EndPoints;
    for (int i = 0; i < EPNumbers; i++)
    {
        if (lUSBEP[i]->Attributes == 1)        //Isoc
        {
            if (lUSBEP[i]->bIn)
                ExUSBIsocInEP = ExUSBDevice->IsocInEndPt;
            else
                ExUSBIsocOutEP = ExUSBDevice->IsocOutEndPt;
        }
        else if (lUSBEP[i]->Attributes == 2)       // Bluk
        {
            if (lUSBEP[i]->bIn)
            {
                ExUSBBlukInEP = ExUSBDevice->BulkInEndPt;
                /*
                PUCHAR ubuf = (PUCHAR)malloc(512);
                UCHAR buf[512] = {0};
                memset(ubuf,0,512);
                LONG b = 0;

                if (ExUSBBlukInEP->XferData(ubuf,b))
                {
                    for (int j = 0; j < 512; j++)
                    {
                        buf[j] = ubuf[j];
                    }
                }
                free(ubuf);
                */
            }
            else
                ExUSBBlukOutEP = ExUSBDevice->BulkOutEndPt;
        }
    } // end of for (int i = 0; i < EPNumbers; i++)
} //end of ExUSB::ExUSB()

ExUSB::~ExUSB()
{
    if (ExUSBDevice->DeviceCount() > 0)
    {
        ExUSBDevice->Close();
        delete(ExUSBDevice);
    }
}
void ExUSB::GetBlockData(UCHAR *data,int *size)
{
    PUCHAR ubuf = (PUCHAR)malloc(512);
    memset(ubuf,0,512);
    CCyIsoPktInfo *pktInfos = new CCyIsoPktInfo();
    LONG b = 512;

    if (ExUSBBlukInEP->XferData(ubuf,b,pktInfos,true))
    {
        *size = (int)b;
        memcpy(data,ubuf,(int)b);
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

