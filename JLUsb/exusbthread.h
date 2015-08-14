#ifndef EXUSBTHREAD_H
#define EXUSBTHREAD_H

#include <QThread>
#include "exusb.h"

class ExUSBThread : public QThread
{
public:
    ExUSBThread();
    ExUSBThread(ExUSB *musb);
    ~ExUSBThread();
    int SetImageWidth(int iwidth);
    int SetImageHeight(int iheight);
    unsigned char *oImage;
signals:
    void GetFrameOK();
protected:
    void run();
private:
    ExUSB *c_exusb;
    unsigned char *image;
    int width;  // image width
    int height; // image height
    int image_nptr; // image number pointer
    void image_init();
};

#endif // EXUSBTHREAD_H
