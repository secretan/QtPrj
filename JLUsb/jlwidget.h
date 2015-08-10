#ifndef JLWIDGET_H
#define JLWIDGET_H

#include <QWidget>
#include "exusb.h"

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

private:
    Ui::JLWidget *ui;
    ExUSB *exusb;
};

#endif // JLWIDGET_H
