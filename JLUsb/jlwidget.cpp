#include "jlwidget.h"
#include "ui_jlwidget.h"
#include <QGraphicsView>
#include <QImage>
#include <QColor>
#include <Qt>
#include <QFile>
#include <QtSerialPort/QSerialPort>

JLWidget::JLWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JLWidget)
{
    ui->setupUi(this);

    exusb = new ExUSB();
    exusb->start();
    exusbthread = new ExUSBThread(exusb);
    jl = new JLOpenCV();
    //img = new QImage(640,480,QImage::Format_RGB32);

    //connect(exusbthread,SIGNAL(exusbthread->GetFrameOK()),this,SLOT(flush_image));
    connect(exusbthread,SIGNAL(GetFrameOK(int)),this,SLOT(flush_image()),Qt::QueuedConnection);
    //connect(exusbthread,SIGNAL(exusbthread->GetFrameOK(int)),exusbthread,SLOT(test_recv()));
    //,Qt::QueuedConnection);
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
    // image
    img = new QImage(640,480,QImage::Format_RGB32);
    scence = new QGraphicsScene;

    QPainter mPainter(ui->histwidget);
    mPainter.setPen(Qt::blue);
    mPainter.drawText(rect(),Qt::AlignCenter,"Hello WOrld");



    // serialport
    QSerialPort *mPort = new QSerialPort();
    mPort->setPortName("COM4");
    mPort->setBaudRate(mPort->Baud115200);
    if (mPort->open(QIODevice::ReadWrite))
    {
        mPort->write("hello");
    }
}

JLWidget::~JLWidget()
{
    exusbthread->terminate();
    exusbthread->~ExUSBThread();
    exusb->terminate();
    exusb->~ExUSB();
    delete img;
    delete scence;
    delete ui;
    //mMediaPlayer->destroyed();
}

void JLWidget::on_pushButton_clicked()
{
    //exusb->ExUSBShow();
    //mMediaPlayer->play();
    //exusbthread->msleep(1000);
    //emit exusbthread->GetFrameOK();
    flush_image();
    jl->test();
}

void JLWidget::on_pushButton_2_clicked()
{
    //mMediaPlayer->pause();
    //exusb->WriteIIC("F:/Project/Ham/USBStudy/QtPrj/QtPrj/JLUsb/CYStream.iic");
    //ExUSBThread *lusbthread = new ExUSBThread(exusb);

    //exusbthread->start(QThread::Priority());
    exusbthread->start();
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
    unsigned char valh = 0;
    unsigned char vall = 0;
    static int max = 0;
    //QFile myfile("H:\/a.txt");
    //if (myfile.exists())
    //    myfile.open(QFile::ReadWrite);
    for (int i = 0; i < 240; i++)
    {
        for (int j = 0; j < 320; j++)
        {
            //valh = exusbthread->oImage[i*2*480+j*2];
            //vall = exusbthread->oImage[i*2*480+j*2+1];
            valh = exusbthread->oImage[(i*320+j)*2];
            vall = exusbthread->oImage[(i*320+j)*2+1];
            //valh = exusbthread.oImage[(j*640+i)*2];
            //vall = exusbthread.oImage[(j*640+i)*2+1];
            //int val = valh+vall*256;
            //myfile.write((char*)&vall,1);
            //myfile.write((char*)&valh,1);
            int val = vall;
            if (val >= 256)
                val = 255;
            //else
                //val= val*6;
            //if (val > max)
            //    max = val;
            if ((i==0)&&(j==0))
                max = val;
            int rgbv = qRgb(val,val,val);
            //int rgbv = qRgba(val,val,val,0x70);
            //if (rgbv<0)
                //rgbv = 0xffffffff;

            img->setPixel(j,i,rgbv);
        }
    }

    scence->addPixmap(QPixmap::fromImage(*img));

    ui->graphicsView->setScene(scence);
    ui->graphicsView->show();
    ui->SendtextBrowser->setText(QString::number(max,10));

    //if (myfile.exists())
    //    myfile.close();
}

void JLWidget::on_pushButton_3_clicked()
{
    exusb->JLProtocolCmd("0x6800","");
}
