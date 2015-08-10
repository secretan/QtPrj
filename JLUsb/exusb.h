#ifndef EXUSB_H
#define EXUSB_H

#include <CyAPI.h>
#include <QImage>
#include <QFile>

class ExUSB
{
public:
    ExUSB();
    ~ExUSB();
    QImage *ExUSBShow();
    void WriteIIC(QString FileName);
private:
    CCyUSBDevice *ExUSBDevice;
    CCyIsocEndPoint *ExUSBIsocInEP;
    CCyIsocEndPoint *ExUSBIsocOutEP;

    // used for test bulk
    CCyBulkEndPoint *ExUSBBlukInEP;
    CCyBulkEndPoint *ExUSBBlukOutEP;
};

#endif // EXUSB_H
