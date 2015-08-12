#include "exusbthread.h"
#include <QDateTime>

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
        image_nptr = image_nptr + size;
        if (image_nptr > 320*240*2)
        {
            //signal()

        }
        if (image_nptr >= 512*1)
        {
            QDateTime mCurTime;
            QString strtime = mCurTime.currentDateTime().toString();

            memcpy(buf,image,512);
            QFile mFile("D:\\Qt\\a.txt");
            if (mFile.exists())
            {
                //mFile.write((char*)buf,512);
                QByteArray a  = mFile.readAll();
                if (a.isEmpty())
                    a.clear();
            }
            mFile.flush();
            mFile.close();
            image_nptr = 0;
            //memset(image,0,width*height*2);
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
        image = (unsigned char *)malloc(width*height*2);
    }
}

