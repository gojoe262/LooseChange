#-------------------------------------------------
#
# Project created by QtCreator 2014-12-12T23:21:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestMVC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mytablemodel.cpp \
    testdto.cpp \
    spinboxdelegate.cpp

HEADERS  += mainwindow.h \
    mytablemodel.h \
    testdto.h \
    spinboxdelegate.h

FORMS    += mainwindow.ui
