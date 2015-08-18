#ifndef JLWIDGET_H
#define JLWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "exusb.h"
#include "exusbthread.h"
#include "jlopencv.h"

namespace Ui {
class JLWidget;
}

class JLWidget : public QWidget
{
    Q_OBJECT

public:
    explicit JLWidget(QWidget *parent = 0);
    ~JLWidget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
//signals:
    void flush_image();

    void on_pushButton_3_clicked();

private:
    Ui::JLWidget *ui;
    ExUSB *exusb;
    ExUSBThread *exusbthread;

    JLOpenCV *jlopencv;

    QMediaPlayer *mMediaPlayer;
    QVideoWidget *mVideoWidget;
};

#endif // JLWIDGET_H
