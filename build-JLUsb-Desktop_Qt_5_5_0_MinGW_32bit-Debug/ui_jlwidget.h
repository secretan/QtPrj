/********************************************************************************
** Form generated from reading UI file 'jlwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JLWIDGET_H
#define UI_JLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JLWidget
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *JLWidget)
    {
        if (JLWidget->objectName().isEmpty())
            JLWidget->setObjectName(QStringLiteral("JLWidget"));
        JLWidget->resize(400, 300);
        pushButton = new QPushButton(JLWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 90, 75, 23));

        retranslateUi(JLWidget);

        QMetaObject::connectSlotsByName(JLWidget);
    } // setupUi

    void retranslateUi(QWidget *JLWidget)
    {
        JLWidget->setWindowTitle(QApplication::translate("JLWidget", "JLWidget", 0));
        pushButton->setText(QApplication::translate("JLWidget", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class JLWidget: public Ui_JLWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JLWIDGET_H
