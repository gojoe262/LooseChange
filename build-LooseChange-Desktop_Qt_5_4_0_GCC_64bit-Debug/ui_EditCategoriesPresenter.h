/********************************************************************************
** Form generated from reading UI file 'EditCategoriesPresenter.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCATEGORIESPRESENTER_H
#define UI_EDITCATEGORIESPRESENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditCategoriesPresenter
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonRemove;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonSave;

    void setupUi(QDialog *EditCategoriesPresenter)
    {
        if (EditCategoriesPresenter->objectName().isEmpty())
            EditCategoriesPresenter->setObjectName(QStringLiteral("EditCategoriesPresenter"));
        EditCategoriesPresenter->resize(401, 304);
        gridLayout = new QGridLayout(EditCategoriesPresenter);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView = new QTableView(EditCategoriesPresenter);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout_2->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonAdd = new QPushButton(EditCategoriesPresenter);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        verticalLayout->addWidget(pushButtonAdd);

        pushButtonRemove = new QPushButton(EditCategoriesPresenter);
        pushButtonRemove->setObjectName(QStringLiteral("pushButtonRemove"));

        verticalLayout->addWidget(pushButtonRemove);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonCancel = new QPushButton(EditCategoriesPresenter);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);

        pushButtonSave = new QPushButton(EditCategoriesPresenter);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        horizontalLayout->addWidget(pushButtonSave);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(EditCategoriesPresenter);

        QMetaObject::connectSlotsByName(EditCategoriesPresenter);
    } // setupUi

    void retranslateUi(QDialog *EditCategoriesPresenter)
    {
        EditCategoriesPresenter->setWindowTitle(QApplication::translate("EditCategoriesPresenter", "Edit Categories", 0));
        pushButtonAdd->setText(QApplication::translate("EditCategoriesPresenter", "&Add", 0));
        pushButtonRemove->setText(QApplication::translate("EditCategoriesPresenter", "&Remove", 0));
        pushButtonCancel->setText(QApplication::translate("EditCategoriesPresenter", "&Cancel", 0));
        pushButtonSave->setText(QApplication::translate("EditCategoriesPresenter", "&Save", 0));
    } // retranslateUi

};

namespace Ui {
    class EditCategoriesPresenter: public Ui_EditCategoriesPresenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCATEGORIESPRESENTER_H
