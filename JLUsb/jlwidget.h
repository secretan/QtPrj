#ifndef JLWIDGET_H
#define JLWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QImage>
#include "cypress/user/exusb.h"
#include "cypress/user/exusbthread.h"
#include "opencv/user/jlopencv.h"

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

    void on_pushButton_3_clicked();

private:
    Ui::JLWidget *ui;
    ExUSB *exusb;
    ExUSBThread *exusbthread;
    JLOpenCV *jl;
    QImage *img;
    QGraphicsScene *scence;
    //QImage *img;
};

#endif // JLWIDGET_H
