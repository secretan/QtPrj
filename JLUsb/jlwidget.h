#ifndef JLWIDGET_H
#define JLWIDGET_H

#include <QWidget>

namespace Ui {
class JLWidget;
}

class JLWidget : public QWidget
{
    Q_OBJECT

public:
    explicit JLWidget(QWidget *parent = 0);
    ~JLWidget();

private:
    Ui::JLWidget *ui;
};

#endif // JLWIDGET_H
