QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = BusApp
TEMPLATE = app
SOURCES += main.cpp \
           mainwindow.cpp
HEADERS += mainwindow.h
FORMS += mainwindow.ui
RESOURCES += resources.qrc