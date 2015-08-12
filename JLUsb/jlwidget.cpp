#include "jlwidget.h"
#include "ui_jlwidget.h"
#include "exusbthread.h"

JLWidget::JLWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JLWidget)
{
    ui->setupUi(this);
    exusb = new ExUSB();
}

JLWidget::~JLWidget()
{
    delete ui;
    exusb->~ExUSB();
}

void JLWidget::on_pushButton_clicked()
{
    exusb->ExUSBShow();
}

void JLWidget::on_pushButton_2_clicked()
{
    //exusb->WriteIIC("F:/Project/Ham/USBStudy/QtPrj/QtPrj/JLUsb/CYStream.iic");
    ExUSBThread *lusbthread = new ExUSBThread(exusb);
    lusbthread->start(QThread::Priority());
    //unsigned char buf[512] = {0,};
    /*
    unsigned char *buf = (unsigned char *)malloc(512);
    memset(buf,0,512);
    unsigned char bbuf[512] = {0,};
    int size = 0;
    exusb->GetBlockData(buf,&size);
    if (size == 0)
        size = buf[2];
    for (int i = 0; i < 512; i++)
    {
        bbuf[i] = buf[i];
    }
    free(buf);
    */
}
