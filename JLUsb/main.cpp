#include "jlwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JLWidget w;
    w.show();

    return a.exec();
}
