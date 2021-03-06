#-------------------------------------------------
#
# Project created by QtCreator 2018-06-01T09:13:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = painter1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui \
    mainwindow.ui

INCLUDEPATH += /usr/local/include \
/usr/local/include/opencv \
/usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_calib3d.so \
/usr/local/lib/libopencv_core.so \
/usr/local/lib/libopencv_features2d.so \
/usr/local/lib/libopencv_flann.so \
/usr/local/lib/libopencv_highgui.so \
/usr/local/lib/libopencv_imgcodecs.so \
/usr/local/lib/libopencv_imgproc.so \
/usr/local/lib/libopencv_ml.so \
/usr/local/lib/libopencv_objdetect.so \
/usr/local/lib/libopencv_photo.so \
/usr/local/lib/libopencv_shape.so \
/usr/local/lib/libopencv_stitching.so \
/usr/local/lib/libopencv_superres.so \
/usr/local/lib/libopencv_video.so \
/usr/local/lib/libopencv_videoio.so \
/usr/local/lib/libopencv_videostab.so \

#LIBS += -L$$PWD/lib/x64/ -lGenApi_MD_VC120_v3_0_Basler_pylon_v5_0
#     -lGCBase_MD_VC120_v3_0_Basler_pylon_v5_0
#     -lPylonBase_MD_VC120_v5_0
#     -lPylonC_MD_VC120
#     -lPylonGUI_MD_VC120_v5_0
#     -lPylonUtility_MD_VC120_v5_0


#INCLUDEPATH += $$PWD/include
#DEPENDPATH += $$PWD/include
QMAKE_CXXFLAGS+=$(shell /opt/pylon5/bin/pylon-config --cflags)
QMAKE_LFLAGS+=$(shell /opt/pylon5/bin/pylon-config --libs-rpath)
LIBS+=$(shell /opt/pylon5/bin/pylon-config --libs)
