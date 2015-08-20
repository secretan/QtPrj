#include "jlopencv.h"
#include <QFile>

JLOpenCV::JLOpenCV()
{
    mMat = new Mat();
}

void JLOpenCV::test()
{
    QFile *qf = new QFile("H:/a.jpg");
    if (qf->exists())
    {
        Mat img = imread("H:/a.jpg");
        imshow("hello",img);
    }
}

