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
    DataAccess/LooseChangeDAO.cpp \
    DataAccess/DTO/TransactionDTO.cpp \
    Presenter/LooseChangePresenter.cpp \
    Test/LooseChangeDAOTest.cpp \
    Utility/Categories.cpp \
    Utility/TransactionType.cpp \
    Delegates/DoubleSpinBoxDelegate.cpp \
    Delegates/DateEditDelegate.cpp \
    DataAccess/CachedDTOList.cpp \
    Presenter/RawViewPresenter.cpp \
    Delegates/TransactionTypeComboBoxDelegate.cpp \
    Delegates/CategoryComboBoxDelegate.cpp \
    Delegates/CommentLineEditDelegate.cpp \
    DataAccess/FileAccess/FileReader.cpp \
    DataAccess/FileAccess/FileWriter.cpp

HEADERS  += \
    DataAccess/LooseChangeDAO.h \
    DataAccess/DTO/TransactionDTO.h \
    Presenter/LooseChangePresenter.h \
    Utility/Categories.h \
    Utility/TransactionType.h \
    Delegates/DoubleSpinBoxDelegate.h \
    Delegates/DateEditDelegate.h \
    DataAccess/CachedDTOList.h \
    Presenter/RawViewPresenter.h \
    Delegates/TransactionTypeComboBoxDelegate.h \
    Delegates/CategoryComboBoxDelegate.h \
    Delegates/CommentLineEditDelegate.h \
    DataAccess/FileAccess/FileReader.h \
    DataAccess/FileAccess/FileWriter.h

FORMS    += loosechangepresenter.ui

OTHER_FILES += \
    Test/test.lc \
    Icons/OpenIcon.png
