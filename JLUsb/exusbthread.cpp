#include "exusbthread.h"

ExUSBThread::ExUSBThread()
{
    image_nptr = 0;
    image_init();
}

ExUSBThread::ExUSBThread(ExUSB *musb)
{
    image_nptr = 0;
    c_exusb = musb;
    image_init();
}
void ExUSBThread::run()
{
    int size;
    uchar buf[512] = {0};

    while(true)
    {
        c_exusb->GetBlockData(&image[image_nptr], &size);
        memcpy(buf,&image[image_nptr],size);
        image_nptr = image_nptr + size;
        if (image_nptr > 320*240*2)
        {
            //signal()

        }
    }
}
ExUSBThread::~ExUSBThread()
{
    free(image);
}
void ExUSBThread::image_init()
{
    if (width != 0 && height != 0)
    {
        image = (unsigned char *)malloc(width*height);
    }
    else
    {
        width = 320;
        height = 240;
        image = (unsigned char *)malloc(width*height);
    }
}

