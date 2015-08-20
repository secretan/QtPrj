#ifndef JLOPENCV_H
#define JLOPENCV_H
#include <QThread>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;

class JLOpenCV : public QThread
{
public:
    JLOpenCV();
    void test();
private:
    Mat *mMat;
};

#endif // JLOPENCV_H
