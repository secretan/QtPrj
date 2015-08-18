#include "jlopencv.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

JLOpenCV::JLOpenCV()
{
    mImage = new Mat();
}

JLOpenCV::~JLOpenCV()
{

}

void JLOpenCV::test()
{/*
    //声明IplImage指针

        IplImage*pImg;

        //载入图片
        pImg=cvLoadImage("E:/OpenCV/FirstOpenCV/home.jpg",1);
        //创建窗口
        cvNamedWindow("Image",1);
        //显示图像
        cvShowImage("Image",pImg);
        //等待按键
        cvWaitKey(0);
        //销毁窗口
        cvDestroyWindow("Image");
        //释放图像
        cvReleaseImage(&pImg);
*/
        Mat Image = imread("a.jpg",1);
        imshow("HELLO",Image);
        return;
}
