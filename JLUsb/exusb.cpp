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
                ExUSBBlukInEP = ExUSBDevice->BulkInEndPt;
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
        //if (ExUSBBlukInEP->XferData())
            a = 1;
        else
             a = 2;
    }
    //OVERLAPPED * overla = new OVERLAPPED;
    //ExUSBBlukInEP->BeginDataXfer(ubuf,512,overla);

    free(ubuf);
    return img;

} // QImage ExUSB::ExUSBShow()

