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
protected:
    void run();
private:
    ExUSB *c_exusb;
    int width;  // image width
    int height; // image height
    unsigned char *image;
    int image_nptr; // image number pointer
    void image_init();
};

#endif // EXUSBTHREAD_H
