#ifndef JLWIDGET_H
#define JLWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "exusb.h"
#include "exusbthread.h"

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
    void flush_image();

private:
    Ui::JLWidget *ui;
    ExUSB *exusb;
    ExUSBThread *exusbthread;
    QMediaPlayer *mMediaPlayer;
    QVideoWidget *mVideoWidget;
};

#endif // JLWIDGET_H
