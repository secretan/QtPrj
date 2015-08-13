#include "exusbthread.h"
#include <QTextStream>

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
    //uchar buf[512] = {0};

    while(true)
    {
        if (!c_exusb->GetUSBDeviceOnFlag())
            continue;
        c_exusb->GetBlockData(&image[image_nptr], &size);
        image_nptr = image_nptr + size;/*
        if (image_nptr > 320*240*2)
        {
            //signal()

        }*/
        // check protocol
        if (size == 512)
        {
            // check head & tail protocol
            if ((image[image_nptr]==0x68)&&(image[image_nptr+1]==0x6e)&&(image[image_nptr+510]==0xe0)&&(image[image_nptr+511]==0x2a))
            {

            }
        }
        if (image_nptr >= 512*320)
        {
#if 0           //write to file for test
            //memcpy(buf,&image[image_nptr],512);
            QFile mFile("D:\\Qt\\b.txt");
            if (mFile.exists())
            {
                mFile.open(QIODevice::WriteOnly);
                //mFile.write((char*)&image[0],480*320);
                for (int i = 0; i < 320; i++)
                {
                    mFile.write((char*)&image[i*512+6],480);
                }
            }
            mFile.flush();
            mFile.close();
#endif
            #if 1
            for (int i = 0; i < 320; i++)
            {
                //mFile.write((char*)&image[i*512+6],480);
                memcpy(oImage,&image[i*512+6],480);
            }
            emit GetFrameOK();
            #endif

            image_nptr = 0;
            //memset(image,0,width*height*2);
        }
        //memset(buf,0,512);
    }
}
ExUSBThread::~ExUSBThread()
{
    free(image);
}
void ExUSBThread::image_init()
{
    width = 320;
    height = 240;
    if (width < 0 && height < 0)
    {
        image = (unsigned char *)malloc(width*height*2);
        oImage = (unsigned char *)malloc(width*height*2);
    }
    else
    {
        image = (unsigned char *)malloc(width*height*2);
        oImage = (unsigned char *)malloc(width*height*2);
    }
}

void ExUSBThread::GetFrameOK()
{

}
