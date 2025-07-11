QT += widgets testlib

TARGET = BusApp
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h
FORMS += mainwindow.ui

test {
    SOURCES += test_mainwindow.cpp
    DEFINES += RUN_TESTS
    CONFIG += console
}
