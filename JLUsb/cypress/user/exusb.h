#ifndef EXUSB_H
#define EXUSB_H

#include <CyAPI.h>
#include <QImage>
#include <QFile>
#include <QThread>
#include <QString>

class ExUSB: public QThread
{
public:
    ExUSB();
    ~ExUSB();
    QImage *ExUSBShow();
    void GetBlockData(UCHAR *data,int *size);
    void WriteIIC(QString FileName);
    int JLProtocolCmd(QString cmd,QString data);
    bool GetUSBDeviceOnFlag();
private:
    CCyUSBDevice *ExUSBDevice;

    // used for video Isoc
    CCyIsocEndPoint *ExUSBIsocInEP;

    // used for test bulk
    CCyBulkEndPoint *ExUSBBlukInEP;
    CCyBulkEndPoint *ExUSBBlukOutEP;

    CCyIsoPktInfo *pktInfos;
    // QThread for detecte/remove devices
    bool deviceFlag;
    void run();
    // detect devices
    bool deviceDetect();
};

#endif // EXUSB_H
