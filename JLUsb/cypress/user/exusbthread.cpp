#include "exusbthread.h"
#include <QTextStream>
#include <Qt>


ExUSBThread::ExUSBThread(ExUSB *musb)
{
    image_nptr = 0;
    frame_start = false;
    c_exusb = musb;
    image_init();
    //connect(this,SIGNAL(GetFrameOK(int)),this,SLOT(test_recv()));
}
void ExUSBThread::run()
{
    int size;
    static int count = 0;
    uchar buf[16] = {0};

    while(true)
    {
        if (!c_exusb->GetUSBDeviceOnFlag())
            continue;
        c_exusb->GetBlockData(&image[image_nptr], &size);

        if (size == 16)
        {
            //80 00 88 FF 80 00 80 00 80 00 80 00 80 88 80 00
            //E0 00 E4 00 E8 00 EC 00 F0 00 F4 00 F8 00 FB 00
            memcpy(buf,&image[image_nptr],size);
            //if (image[image_nptr+1] == 0x85)
            if (buf[1] == 0x85)
            {
                if (frame_start)
                {
                    image_nptr = 0;
                    frame_start = false;
                    memcpy(oImage,&image[0],320*240*2);
                    emit GetFrameOK(10);
                    memset(image,0,width*height*2);
                }
            }
            //else if (image[image_nptr+1] == 0x68)
            else if (buf[1] == 0x68)
            {
                image_nptr = 0;
                frame_start = true;
                count = 0;
            }
        }
        else if (size > 0)
        {
            image_nptr = image_nptr+size;
            if (image_nptr > 320*240*2)
                image_nptr = 0;
            count++;
        }
        /*
        image_nptr = image_nptr+size;
        if (image_nptr>320*240)
        {
            memcpy(buf,&image[0],16);
            image_nptr = 0;
        }*/
        /*
        // check protocol
        if (size == 512)
        {
            // check head & tail protocol
            if ((image[image_nptr]==0x68)&&(image[image_nptr+1]==0x6e)&&(image[image_nptr+510]==0xe0)&&(image[image_nptr+511]==0x2a))
            {
                int frame_index = image[image_nptr+4]*256+image[image_nptr+5];
                if (image_nptr != frame_index*512)
                {
                    memcpy(&image[frame_index*512],&image[image_nptr],512);
                    image_nptr = (frame_index+1)*512;
                }
                else
                {
                    image_nptr = image_nptr + size;
                }
            }
        }
        if (image_nptr == 512*(height*width*2/480))
        {

            for (int i = 0; i < (int)height*width*2/480; i++)
            {
                //mFile.write((char*)&image[i*512+6],480);
                memcpy(&oImage[i*480],&image[i*512+6],480);
            }
            emit GetFrameOK(10);
            //test_sig();
            /* /
            QFile mFile("D:\\Qt\\c.txt");
            if (mFile.exists())
            {
                mFile.open(QIODevice::WriteOnly);
                //mFile.write((char*)&image[0],480*320);
                for (int i = 0; i < (int)height*width*2/480; i++)
                {
                    mFile.write((char*)&image[i*512+6],480);
                }
            }
            mFile.flush();
            mFile.close();
            / * /
            image_nptr = 0;
            memset(image,0,width*height*2);
        }
        //memset(buf,0,512);
        */
    }
}
ExUSBThread::~ExUSBThread()
{
    free(image);
}
void ExUSBThread::image_init()
{
    width = 640;
    height = 480;
    if (width < 0 && height < 0)
    {
        image = (unsigned char *)malloc(width*height*2*512/480);
        oImage = (unsigned char *)malloc(width*height*2);
    }
    else
    {
        image = (unsigned char *)malloc(width*height*2*512/480);
        oImage = (unsigned char *)malloc(width*height*2);
    }
}


