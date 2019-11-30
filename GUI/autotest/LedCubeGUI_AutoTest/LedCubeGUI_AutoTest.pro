QT += testlib
QT += core gui widgets serialport
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_ledcubegui_autotest.cpp \
    ./mainwindow.cpp

FORMS += \
    ./mainwindow.ui

HEADERS += \
    ./mainwindow.h
