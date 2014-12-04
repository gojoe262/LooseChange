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
    Data/Accessors/TransactionDAO.cpp \
    Data/Objects/TransactionDTO.cpp \
    Presenter/LooseChangePresenter.cpp \
    Test/LooseChangeDAOTest.cpp \
    Utility/Categories.cpp \
    Utility/TransactionType.cpp \
    Delegates/DoubleSpinBoxDelegate.cpp \
    Delegates/DateEditDelegate.cpp \
    Data/Cache/CachedData.cpp \
    Presenter/RawViewPresenter.cpp \
    Delegates/TransactionTypeComboBoxDelegate.cpp \
    Delegates/CategoryComboBoxDelegate.cpp \
    Delegates/CommentLineEditDelegate.cpp \
    Data/FileAccess/FileReader.cpp \
    Data/FileAccess/FileWriter.cpp \
    Data/Objects/CategoryDTO.cpp \
    Data/Accessors/CategoryDAO.cpp

HEADERS  += \
    Data/Accessors/TransactionDAO.h \
    Data/Objects/TransactionDTO.h \
    Presenter/LooseChangePresenter.h \
    Utility/Categories.h \
    Utility/TransactionType.h \
    Delegates/DoubleSpinBoxDelegate.h \
    Delegates/DateEditDelegate.h \
    Data/Cache/CachedData.h \
    Presenter/RawViewPresenter.h \
    Delegates/TransactionTypeComboBoxDelegate.h \
    Delegates/CategoryComboBoxDelegate.h \
    Delegates/CommentLineEditDelegate.h \
    Data/FileAccess/FileReader.h \
    Data/FileAccess/FileWriter.h \
    Data/Objects/CategoryDTO.h \
    Data/Accessors/CategoryDAO.h

FORMS    += loosechangepresenter.ui

OTHER_FILES += \
    Test/test.lc \
    Icons/OpenIcon.png
