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
        jlwidget.cpp \
    exusb.cpp \
    exusbthread.cpp \
    jlopencv.cpp

HEADERS  += jlwidget.h \
    exusb.h \
    exusbthread.h \
    jlopencv.h

FORMS    += jlwidget.ui

# Cypress USB lib
unix:!macx|win32: LIBS += -L$$PWD/cypress/lib/x64/ -lCyAPI
win32: LIBS += -lsetupapi

INCLUDEPATH += $$PWD/cypress/inc
DEPENDPATH += $$PWD/cypress/inc

# OpenCV lib
unix:!macx|win32: LIBS += -L$$PWD/opencv/lib/	\
                            -lopencv_core2410d  \
                            -lopencv_calib3d2410d   \
                            -lopencv_contrib2410d   \
                            -lopencv_features2d2410d    \
                            -lopencv_flann2410d         \
                            -lopencv_gpu2410d           \
                            -lopencv_highgui2410d     \
                            -lopencv_imgproc2410d     \
                            -lopencv_legacy2410d      \
                            -lopencv_ml2410d          \
                            -lopencv_nonfree2410d       \
                            -lopencv_objdetect2410d   \
                            -lopencv_ocl2410d         \
                            -lopencv_ts2410d              \
                            -lopencv_video2410d       \
                            -lopencv_videostab2410d   \
                            -lopencv_photo2410d         \
                            -lopencv_stitching2410d   \
                            -lopencv_superres2410d

INCLUDEPATH += $$PWD/opencv/inc
INCLUDEPATH += $$PWD/opencv/inc/opencv
INCLUDEPATH += $$PWD/opencv/inc/opencv2
DEPENDPATH += $$PWD/opencv/inc
