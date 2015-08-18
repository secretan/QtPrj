#ifndef JLOPENCV_H
#define JLOPENCV_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

//namespace cv {
//class JLOpenCV;
//}
using namespace cv;
using namespace std;

class JLOpenCV
{
    //Q_OBJECT
public:
    JLOpenCV();
    ~JLOpenCV();
    void test();

private:
    //IplImage *pImg;
    Mat *mImage;
};

#endif // JLOPENCV_H
