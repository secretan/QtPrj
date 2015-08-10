#include "jlwidget.h"
#include "ui_jlwidget.h"

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
}
