#-------------------------------------------------
#
# Project created by QtCreator 2014-08-20T21:23:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LooseChange
TEMPLATE = app


SOURCES += main.cpp \
    LooseChangePresenter.cpp \
    LooseChangeDTO.cpp \
    LooseChangeDAO.cpp

HEADERS  += \
    LooseChangePresenter.h \
    LooseChangeDTO.h \
    Type.h \
    LooseChangeDAO.h

FORMS    += loosechangepresenter.ui
