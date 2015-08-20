#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T21:56:14
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JLUsb
TEMPLATE = app


SOURCES += main.cpp\
    exusb.cpp \
    exusbthread.cpp \
    jlopencv.cpp \
    jlwidget.cpp

HEADERS  += jlwidget.h \
    exusb.h \
    exusbthread.h \
    jlopencv.h

FORMS    += jlwidget.ui

# OpenCV lib
unix:!macx|win32: LIBS += -L$$PWD/opencv/lib/	\
                            -lopencv_core2410  \
                            -lopencv_calib3d2410   \
                            -lopencv_contrib2410   \
                            -lopencv_features2d2410    \
                            -lopencv_flann2410         \
                            -lopencv_gpu2410           \
                            -lopencv_highgui2410     \
                            -lopencv_imgproc2410     \
                            -lopencv_legacy2410      \
                            -lopencv_ml2410          \
                            -lopencv_nonfree2410       \
                            -lopencv_objdetect2410   \
                            -lopencv_ocl2410        \
                            -lopencv_ts2410              \
                            -lopencv_video2410       \
                            -lopencv_videostab2410   \
                            -lopencv_photo2410         \
                            -lopencv_stitching2410   \
                            -lopencv_superres2410

INCLUDEPATH += $$PWD/opencv/inc
INCLUDEPATH += $$PWD/opencv/inc/opencv
INCLUDEPATH += $$PWD/opencv/inc/opencv2
DEPENDPATH += $$PWD/opencv/inc
# Cypress USB lib
unix:!macx|win32: LIBS += -L$$PWD/cypress/lib/x64/ -lCyAPI
win32: LIBS += -lsetupapi

INCLUDEPATH += $$PWD/cypress/inc
DEPENDPATH += $$PWD/cypress/inc

