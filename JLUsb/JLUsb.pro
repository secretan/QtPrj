#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T21:56:14
#
#-------------------------------------------------

#QT       += core gui multimedia multimediawidgets widgets serialport
QT       += core gui widgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JLUsb
TEMPLATE = app


SOURCES += main.cpp\
    jlwidget.cpp \
    cypress/user/exusb.cpp \
    cypress/user/exusbthread.cpp \
    opencv/user/jlopencv.cpp \
    jlpaint.cpp

HEADERS  += jlwidget.h \
    cypress/user/exusb.h \
    cypress/user/exusbthread.h \
    opencv/user/jlopencv.h \
    jlpaint.h

FORMS    += jlwidget.ui

# Cypress USB lib
unix:!macx|win32: LIBS += -L$$PWD/cypress/lib/x64/ -lCyAPI1
win32: LIBS += -lsetupapi

INCLUDEPATH += $$PWD/cypress/inc
DEPENDPATH += $$PWD/cypress/inc

# OpenCV lib
unix:!macx|win32:  LIBS += -L$$PWD/opencv/lib/	\
                -lopencv_calib3d2410.dll \
                -lopencv_contrib2410.dll \
                -lopencv_core2410.dll \
                -lopencv_features2d2410.dll \
                -lopencv_flann2410.dll \
                -lopencv_gpu2410.dll \
                -lopencv_highgui2410.dll \
                -lopencv_imgproc2410.dll \
                -lopencv_legacy2410.dll \
                -lopencv_ml2410.dll \
                -lopencv_nonfree2410.dll \
                -lopencv_objdetect2410.dll \
                -lopencv_ocl2410.dll \
                -lopencv_photo2410.dll \
                -lopencv_stitching2410.dll \
                -lopencv_superres2410.dll \
                -lopencv_ts2410 \
                -lopencv_video2410.dll \
                -lopencv_videostab2410.dll

INCLUDEPATH += $$PWD/opencv/inc
DEPENDPATH += $$PWD/opencv/inc

