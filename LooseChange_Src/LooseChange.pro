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
    UI/Presenter/LooseChangePresenter.cpp \
    Utility/TransactionType.cpp \
    UI/Delegates/DoubleSpinBoxDelegate.cpp \
    UI/Delegates/DateEditDelegate.cpp \
    Data/Cache/CachedData.cpp \
    UI/Delegates/TransactionTypeComboBoxDelegate.cpp \
    UI/Delegates/CategoryComboBoxDelegate.cpp \
    UI/Delegates/CommentLineEditDelegate.cpp \
    Data/FileAccess/FileReader.cpp \
    Data/FileAccess/FileWriter.cpp \
    Data/DTO/CategoryDTO.cpp \
    Data/DAO/CategoryDAO.cpp \
    UI/Models/RawViewTableModel.cpp \
    UI/Presenter/EditCategoriesPresenter.cpp \
    UI/Models/EditCategoriesTableModel.cpp \
    Utility/UniqueKeyGenerator.cpp \
    UI/Presenter/RawViewPresenter.cpp \
    Test/TestBase.cpp \
    Test/Data/DAO/TransactionDAOTest.cpp \
    Test/Data/DAO/CategoryDAOTest.cpp

HEADERS  += \
    Data/DAO/TransactionDAO.h \
    Data/DTO/TransactionDTO.h \
    UI/Presenter/LooseChangePresenter.h \
    Utility/TransactionType.h \
    UI/Delegates/DoubleSpinBoxDelegate.h \
    UI/Delegates/DateEditDelegate.h \
    Data/Cache/CachedData.h \
    UI/Delegates/TransactionTypeComboBoxDelegate.h \
    UI/Delegates/CategoryComboBoxDelegate.h \
    UI/Delegates/CommentLineEditDelegate.h \
    Data/FileAccess/FileReader.h \
    Data/FileAccess/FileWriter.h \
    Data/DTO/CategoryDTO.h \
    Data/DAO/CategoryDAO.h \
    UI/Models/RawViewTableModel.h \
    UI/Presenter/EditCategoriesPresenter.h \
    UI/Models/EditCategoriesTableModel.h \
    Utility/UniqueKeyGenerator.h \
    UI/Presenter/RawViewPresenter.h \
    Test/TestBase.h \
    Test/Data/DAO/TransactionDAOTest.h \
    Test/Data/DAO/CategoryDAOTest.h

FORMS    += \
    UI/Presenter/EditCategoriesPresenter.ui \
    UI/Presenter/LooseChangePresenter.ui \
    UI/Presenter/RawViewPresenter.ui

DISTFILES += \
    Test/testSaveFile_JSON.json
