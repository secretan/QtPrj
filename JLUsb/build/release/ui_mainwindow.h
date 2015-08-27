/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *SystemTab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *USBdevName;
    QLabel *label_2;
    QLabel *USBdevVPInfo;
    QLabel *label_4;
    QLabel *USBdevEPnumber;
    QLabel *label_5;
    QWidget *VideoTab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(817, 481);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 811, 411));
        SystemTab = new QWidget();
        SystemTab->setObjectName(QStringLiteral("SystemTab"));
        groupBox = new QGroupBox(SystemTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 301, 161));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 61, 16));
        USBdevName = new QLabel(groupBox);
        USBdevName->setObjectName(QStringLiteral("USBdevName"));
        USBdevName->setGeometry(QRect(90, 30, 201, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 71, 16));
        USBdevVPInfo = new QLabel(groupBox);
        USBdevVPInfo->setObjectName(QStringLiteral("USBdevVPInfo"));
        USBdevVPInfo->setGeometry(QRect(90, 50, 141, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 71, 16));
        USBdevEPnumber = new QLabel(groupBox);
        USBdevEPnumber->setObjectName(QStringLiteral("USBdevEPnumber"));
        USBdevEPnumber->setGeometry(QRect(100, 70, 131, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 100, 131, 16));
        tabWidget->addTab(SystemTab, QString());
        VideoTab = new QWidget();
        VideoTab->setObjectName(QStringLiteral("VideoTab"));
        tabWidget->addTab(VideoTab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 817, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "USB Information", 0));
        label->setText(QApplication::translate("MainWindow", "USB Device", 0));
        USBdevName->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "USB VID&PID", 0));
        USBdevVPInfo->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "USB EndPoint", 0));
        USBdevEPnumber->setText(QApplication::translate("MainWindow", "EndPointNum", 0));
        label_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(SystemTab), QApplication::translate("MainWindow", "\347\263\273\347\273\237\346\216\247\345\210\266", 0));
        tabWidget->setTabText(tabWidget->indexOf(VideoTab), QApplication::translate("MainWindow", "\350\247\206\351\242\221\351\207\207\351\233\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
