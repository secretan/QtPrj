#include "jlwidget.h"
#include "ui_jlwidget.h"

JLWidget::JLWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JLWidget)
{
    ui->setupUi(this);
}

JLWidget::~JLWidget()
{
    delete ui;
}
