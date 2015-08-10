#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T21:56:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JLUsb
TEMPLATE = app


SOURCES += main.cpp\
        jlwidget.cpp \
    exusb.cpp

HEADERS  += jlwidget.h \
    exusb.h

FORMS    += jlwidget.ui

unix:!macx|win32: LIBS += -L$$PWD/cypress/lib/x64/ -lCyAPI
win32: LIBS += -lsetupapi


INCLUDEPATH += $$PWD/cypress/inc
DEPENDPATH += $$PWD/cypress/inc
