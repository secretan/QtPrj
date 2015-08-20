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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JLWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *SendlineEdit;
    QTextBrowser *SendtextBrowser;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_3;

    void setupUi(QWidget *JLWidget)
    {
        if (JLWidget->objectName().isEmpty())
            JLWidget->setObjectName(QStringLiteral("JLWidget"));
        JLWidget->resize(962, 538);
        JLWidget->setMinimumSize(QSize(838, 424));
        pushButton = new QPushButton(JLWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 50, 75, 23));
        pushButton_2 = new QPushButton(JLWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 10, 75, 23));
        SendlineEdit = new QLineEdit(JLWidget);
        SendlineEdit->setObjectName(QStringLiteral("SendlineEdit"));
        SendlineEdit->setGeometry(QRect(30, 80, 201, 20));
        SendtextBrowser = new QTextBrowser(JLWidget);
        SendtextBrowser->setObjectName(QStringLiteral("SendtextBrowser"));
        SendtextBrowser->setGeometry(QRect(30, 110, 201, 192));
        graphicsView = new QGraphicsView(JLWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(240, 10, 721, 501));
        pushButton_3 = new QPushButton(JLWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 310, 75, 23));

        retranslateUi(JLWidget);

        QMetaObject::connectSlotsByName(JLWidget);
    } // setupUi

    void retranslateUi(QWidget *JLWidget)
    {
        JLWidget->setWindowTitle(QApplication::translate("JLWidget", "JLWidget", 0));
        pushButton->setText(QApplication::translate("JLWidget", "Send", 0));
        pushButton_2->setText(QApplication::translate("JLWidget", "Download", 0));
        pushButton_3->setText(QApplication::translate("JLWidget", "ResetDev", 0));
    } // retranslateUi

};

namespace Ui {
    class JLWidget: public Ui_JLWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JLWIDGET_H
