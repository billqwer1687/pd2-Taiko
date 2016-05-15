#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T14:08:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    button.cpp \
    drum.cpp

HEADERS  += mainwindow.h \
    scene.h \
    button.h \
    drum.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
