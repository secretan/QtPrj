#include "jlwidget.h"
#include "ui_jlwidget.h"
#include "exusbthread.h"
#include <QGraphicsView>
#include <QImage>
#include <QColor>
#include <Qt>

JLWidget::JLWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JLWidget)
{
    ui->setupUi(this);
    exusb = new ExUSB();
    exusb->start();
    exusbthread = new ExUSBThread(exusb);

    //connect(exusbthread,SIGNAL(exusbthread->GetFrameOK()),this,SLOT(flush_image));
    connect(exusbthread,SIGNAL(GetFrameOK()),this,SLOT(flush_image()),Qt::DirectConnection);
    //connect(this,SIGNAL(flush_image()),exusbthread,SLOT(GetFrameOK()),Qt::DirectConnection);
    //mVideoWidget.setParent(this);
    /*
    mVideoWidget = new QVideoWidget();
    mMediaPlayer = new QMediaPlayer;
    QMediaContent mp = QUrl::fromLocalFile("E:\\zlj_bd.mp4");
    mMediaPlayer->setMedia(mp);

    mMediaPlayer->setVideoOutput(mVideoWidget);
    //mVideoWidget->setBaseSize(1024,576);
    mVideoWidget->setGeometry(0,0,1024,576);
    mVideoWidget->show();
    mMediaPlayer->play();
    */
}

JLWidget::~JLWidget()
{
    exusb->terminate();
    exusb->~ExUSB();
    delete ui;
    //mMediaPlayer->destroyed();
}

void JLWidget::on_pushButton_clicked()
{
    //exusb->ExUSBShow();
    //mMediaPlayer->play();
    exusbthread->msleep(1000);
    //emit exusbthread->GetFrameOK();
    flush_image();
}

void JLWidget::on_pushButton_2_clicked()
{
    //mMediaPlayer->pause();
    //exusb->WriteIIC("F:/Project/Ham/USBStudy/QtPrj/QtPrj/JLUsb/CYStream.iic");
    //ExUSBThread *lusbthread = new ExUSBThread(exusb);
    exusbthread->start(QThread::Priority());
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
void JLWidget::flush_image()
{
    QImage *img = new QImage(320,240,QImage::Format_RGB32);
    unsigned char valh = 0;
    unsigned char vall = 0;
    for (int i = 0; i < 320; i++)
    {
        for (int j = 0; j < 240; j++)
        {
            valh = exusbthread->oImage[i*2*240+j*2];
            vall = exusbthread->oImage[i*2*240+j*2+1];
            int val = valh+vall*256;
            int rgbv = qRgb(val,val,val);
            img->setPixel(i,j,rgbv);
        }
    }
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(*img));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}
