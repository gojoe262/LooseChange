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
    Data/DAO/TransactionDAO.cpp \
    Data/DTO/TransactionDTO.cpp \
    Presenter/LooseChangePresenter.cpp \
    Utility/TransactionType.cpp \
    Delegates/DoubleSpinBoxDelegate.cpp \
    Delegates/DateEditDelegate.cpp \
    Data/Cache/CachedData.cpp \
    Delegates/TransactionTypeComboBoxDelegate.cpp \
    Delegates/CategoryComboBoxDelegate.cpp \
    Delegates/CommentLineEditDelegate.cpp \
    Data/FileAccess/FileReader.cpp \
    Data/FileAccess/FileWriter.cpp \
    Data/DTO/CategoryDTO.cpp \
    Data/DAO/CategoryDAO.cpp \
    Models/RawViewTableModel.cpp \
    Presenter/EditCategoriesPresenter.cpp \
    Models/EditCategoriesTableModel.cpp \
    Utility/UniqueKeyGenerator.cpp \
    Presenter/RawViewWidget.cpp

HEADERS  += \
    Data/DAO/TransactionDAO.h \
    Data/DTO/TransactionDTO.h \
    Presenter/LooseChangePresenter.h \
    Utility/TransactionType.h \
    Delegates/DoubleSpinBoxDelegate.h \
    Delegates/DateEditDelegate.h \
    Data/Cache/CachedData.h \
    Delegates/TransactionTypeComboBoxDelegate.h \
    Delegates/CategoryComboBoxDelegate.h \
    Delegates/CommentLineEditDelegate.h \
    Data/FileAccess/FileReader.h \
    Data/FileAccess/FileWriter.h \
    Data/DTO/CategoryDTO.h \
    Data/DAO/CategoryDAO.h \
    Models/RawViewTableModel.h \
    Presenter/EditCategoriesPresenter.h \
    Models/EditCategoriesTableModel.h \
    Utility/UniqueKeyGenerator.h \
    Presenter/RawViewWidget.h

FORMS    += \
    Presenter/EditCategoriesPresenter.ui \
    Presenter/LooseChangePresenter.ui \
    Presenter/RawViewWidget.ui

OTHER_FILES += \
    Test/test.lc

DISTFILES += \
    Test/testSaveFile_JSON.json
