#ifndef EXUSB_H
#define EXUSB_H

#include <CyAPI.h>
#include <QImage>

class ExUSB
{
public:
    ExUSB();
    ~ExUSB();
    QImage *ExUSBShow();
private:
    CCyUSBDevice *ExUSBDevice;
    CCyIsocEndPoint *ExUSBIsocInEP;
    CCyIsocEndPoint *ExUSBIsocOutEP;

    // used for test bulk
    CCyBulkEndPoint *ExUSBBlukInEP;
    CCyBulkEndPoint *ExUSBBlukOutEP;
};

#endif // EXUSB_H
