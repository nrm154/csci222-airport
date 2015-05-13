#-------------------------------------------------
#
# Project created by QtCreator 2015-05-06T11:39:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ConfigurationSettings.cpp \
    uiloginscreen.cpp

HEADERS  += mainwindow.h \
    ConfigurationSettings.h \
    uiloginscreen.h

FORMS    += mainwindow.ui \
    uiloginscreen.ui

DISTFILES += \
    config.cfg \
    copyConfig.bat \
    setupWindowsDirectories.bat


