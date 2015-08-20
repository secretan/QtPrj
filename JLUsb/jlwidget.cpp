#include "jlwidget.h"
#include "ui_jlwidget.h"
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
}

JLWidget::~JLWidget()
{
    exusbthread->terminate();
    exusbthread->~ExUSBThread();
    exusb->terminate();
    exusb->~ExUSB();
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
    int max = 0;
    QImage *img = new QImage(640,480,QImage::Format_RGB32);
    for (int i = 0; i < 640; i++)
    {
        for (int j = 0; j < 480; j++)
        {
            //valh = exusbthread->oImage[i*2*480+j*2];
            //vall = exusbthread->oImage[i*2*480+j*2+1];
            valh = exusbthread->oImage[(j*640+i)*2];
            vall = exusbthread->oImage[(j*640+i)*2+1];
            //valh = exusbthread.oImage[(j*640+i)*2];
            //vall = exusbthread.oImage[(j*640+i)*2+1];
            int val = valh+vall*256;
            if (val >= 256)
                val = 255;
            //else
                //val= val*6;
            if (val > max)
                max = val;
            int rgbv = qRgb(val,val,val);
            img->setPixel(i,j,rgbv);
        }
    }
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(*img));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->SendtextBrowser->setText(QString::number(max,10));

}

void JLWidget::on_pushButton_3_clicked()
{
    exusb->JLProtocolCmd("0x6800","");
}
