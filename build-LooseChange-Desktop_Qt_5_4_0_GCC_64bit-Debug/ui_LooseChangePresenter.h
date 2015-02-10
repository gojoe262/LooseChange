/********************************************************************************
** Form generated from reading UI file 'LooseChangePresenter.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOSECHANGEPRESENTER_H
#define UI_LOOSECHANGEPRESENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LooseChangePresenter
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionEdit_Categories;
    QAction *actionE_xit;
    QWidget *centralWidget;
    QToolButton *toolButtonOpen;
    QToolButton *toolButtonShowRawViewPresenter;
    QToolButton *toolButtonSave;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;

    void setupUi(QMainWindow *LooseChangePresenter)
    {
        if (LooseChangePresenter->objectName().isEmpty())
            LooseChangePresenter->setObjectName(QStringLiteral("LooseChangePresenter"));
        LooseChangePresenter->resize(762, 417);
        actionOpen = new QAction(LooseChangePresenter);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/OpenIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave = new QAction(LooseChangePresenter);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SaveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionEdit_Categories = new QAction(LooseChangePresenter);
        actionEdit_Categories->setObjectName(QStringLiteral("actionEdit_Categories"));
        actionE_xit = new QAction(LooseChangePresenter);
        actionE_xit->setObjectName(QStringLiteral("actionE_xit"));
        centralWidget = new QWidget(LooseChangePresenter);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toolButtonOpen = new QToolButton(centralWidget);
        toolButtonOpen->setObjectName(QStringLiteral("toolButtonOpen"));
        toolButtonOpen->setGeometry(QRect(91, 10, 28, 27));
        toolButtonOpen->setText(QStringLiteral(""));
        toolButtonOpen->setIcon(icon);
        toolButtonOpen->setIconSize(QSize(20, 20));
        toolButtonShowRawViewPresenter = new QToolButton(centralWidget);
        toolButtonShowRawViewPresenter->setObjectName(QStringLiteral("toolButtonShowRawViewPresenter"));
        toolButtonShowRawViewPresenter->setGeometry(QRect(10, 13, 75, 21));
        toolButtonSave = new QToolButton(centralWidget);
        toolButtonSave->setObjectName(QStringLiteral("toolButtonSave"));
        toolButtonSave->setEnabled(false);
        toolButtonSave->setGeometry(QRect(125, 10, 28, 27));
        toolButtonSave->setText(QStringLiteral(""));
        toolButtonSave->setIcon(icon1);
        toolButtonSave->setIconSize(QSize(20, 20));
        LooseChangePresenter->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(LooseChangePresenter);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setContextMenuPolicy(Qt::PreventContextMenu);
        mainToolBar->setMovable(true);
        LooseChangePresenter->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(LooseChangePresenter);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 762, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        LooseChangePresenter->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionE_xit);
        menuTools->addAction(actionEdit_Categories);

        retranslateUi(LooseChangePresenter);

        QMetaObject::connectSlotsByName(LooseChangePresenter);
    } // setupUi

    void retranslateUi(QMainWindow *LooseChangePresenter)
    {
        LooseChangePresenter->setWindowTitle(QApplication::translate("LooseChangePresenter", "LooseChangePresenter", 0));
        actionOpen->setText(QApplication::translate("LooseChangePresenter", "&Open", 0));
        actionOpen->setShortcut(QApplication::translate("LooseChangePresenter", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("LooseChangePresenter", "&Save", 0));
        actionSave->setShortcut(QApplication::translate("LooseChangePresenter", "Ctrl+S", 0));
        actionEdit_Categories->setText(QApplication::translate("LooseChangePresenter", "&Edit Categories", 0));
        actionE_xit->setText(QApplication::translate("LooseChangePresenter", "E&xit", 0));
        actionE_xit->setShortcut(QApplication::translate("LooseChangePresenter", "Ctrl+Q", 0));
        toolButtonShowRawViewPresenter->setText(QApplication::translate("LooseChangePresenter", "Raw View", 0));
        menuFile->setTitle(QApplication::translate("LooseChangePresenter", "File", 0));
        menuTools->setTitle(QApplication::translate("LooseChangePresenter", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class LooseChangePresenter: public Ui_LooseChangePresenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOSECHANGEPRESENTER_H
