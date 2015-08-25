#ifndef EXUSBTHREAD_H
#define EXUSBTHREAD_H
#include "exusb.h"
#include <QThread>

class ExUSBThread : public QThread
{
    Q_OBJECT
public:
    ExUSBThread(ExUSB *musb);
    ~ExUSBThread();
    int SetImageWidth(int iwidth);
    int SetImageHeight(int iheight);
    unsigned char *oImage;
protected:
    void run();
private:
    ExUSB *c_exusb;
    unsigned char *image;
    int width;  // image width
    int height; // image height
    int image_nptr; // image number pointer
    bool frame_start;
    void image_init();
    void test_sig();
signals:
    void GetFrameOK(int num);
};

#endif // EXUSBTHREAD_H
