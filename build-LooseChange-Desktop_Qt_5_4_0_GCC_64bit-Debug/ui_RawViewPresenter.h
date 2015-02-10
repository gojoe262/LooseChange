/********************************************************************************
** Form generated from reading UI file 'RawViewPresenter.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAWVIEWPRESENTER_H
#define UI_RAWVIEWPRESENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RawViewPresenter
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *RawViewPresenter)
    {
        if (RawViewPresenter->objectName().isEmpty())
            RawViewPresenter->setObjectName(QStringLiteral("RawViewPresenter"));
        RawViewPresenter->resize(400, 300);
        verticalLayout = new QVBoxLayout(RawViewPresenter);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(RawViewPresenter);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(RawViewPresenter);

        QMetaObject::connectSlotsByName(RawViewPresenter);
    } // setupUi

    void retranslateUi(QWidget *RawViewPresenter)
    {
        RawViewPresenter->setWindowTitle(QApplication::translate("RawViewPresenter", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class RawViewPresenter: public Ui_RawViewPresenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAWVIEWPRESENTER_H
