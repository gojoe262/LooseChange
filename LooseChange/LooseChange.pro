#-------------------------------------------------
#
# Project created by QtCreator 2014-08-20T21:23:31
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LooseChange
TEMPLATE = app


SOURCES += main.cpp \
    DAO/LooseChangeDAO.cpp \
    DTO/LooseChangeDTO.cpp \
    Presenter/LooseChangePresenter.cpp \
    Test/LooseChangeDAOTest.cpp \
    Model/TableModel.cpp \
    Utility/Categories.cpp \
    Utility/TransactionType.cpp \
    Utility/FileDialog.cpp \
    Presenter/LooseChangePresenterHelper.cpp \
    DTO/CachedDTOList.cpp \
    Delegates/DoubleSpinBoxDelegate.cpp \
    Delegates/DateEditDelegate.cpp

HEADERS  += \
    DAO/LooseChangeDAO.h \
    DTO/LooseChangeDTO.h \
    Presenter/LooseChangePresenter.h \
    Utility/Categories.h \
    Model/TableModel.h \
    Utility/TransactionType.h \
    Utility/FileDialog.h \
    Presenter/LooseChangePresenterHelper.h \
    DTO/CachedDTOList.h \
    View/TableView.h \
    Delegates/DoubleSpinBoxDelegate.h \
    Delegates/DateEditDelegate.h

FORMS    += loosechangepresenter.ui

OTHER_FILES += \
    Test/test.lc \
    Icons/OpenIcon.png
