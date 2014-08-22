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
    LooseChangeDAO.cpp \
    DAO/LooseChangeDAO.cpp \
    DTO/LooseChangeDTO.cpp \
    Presenter/LooseChangePresenter.cpp

HEADERS  += \
    LooseChangePresenter.h \
    LooseChangeDTO.h \
    Type.h \
    LooseChangeDAO.h \
    DAO/LooseChangeDAO.h \
    DTO/LooseChangeDTO.h \
    Presenter/LooseChangePresenter.h \
    Utility/Type.h

FORMS    += loosechangepresenter.ui
