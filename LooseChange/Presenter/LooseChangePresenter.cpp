#include "LooseChangePresenter.h"
#include "ui_loosechangepresenter.h"

#include<QDebug>

#include <QFileDialog>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <Utility/TransactionType.h>
#include <Utility/Categories.h>
#include <Delegates/DoubleSpinBoxDelegate.h>
#include <Delegates/DateEditDelegate.h>


LooseChangePresenter::LooseChangePresenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LooseChangePresenter)
{
    ///Sets up the UI
    ui->setupUi(this);
    this->setCentralWidget(ui->tabWidget);

    ///Add Buttons to the toolbar
    ui->mainToolBar->addWidget(ui->toolButtonOpen);
    ui->mainToolBar->addWidget(ui->toolButtonSave);




    /// http://iconsetc.com/icon/bfa_folder-open/?style=simple-black
    //Used to set edit triggers. Ex: signal or double click

    cachedData = new CachedData();
    rawView = new RawViewPresenter(ui->tableWidgetRawView, cachedData, this);
    connect(cachedData, SIGNAL(MarkClean()), this, SLOT(DisableSaveButton()));
    connect(cachedData, SIGNAL(MarkDirty()), this, SLOT(EnableSaveButton()));

    rawView->Load();


}

LooseChangePresenter::~LooseChangePresenter()
{
    delete rawView;
    delete cachedData;
    delete ui;

}

void LooseChangePresenter::on_toolButtonOpen_clicked()
{

    QString fileLocation = QFileDialog::getOpenFileName(this, tr("Open File"), "./",
                                                        tr("LooseChange Files (*.json);;All Files (*.* *"));
    if(fileLocation != "")
    {
        cachedData->ReadFile(fileLocation);
        rawView->Load();
        fileLocationTemp = fileLocation;
    }
}

void LooseChangePresenter::on_toolButtonSave_clicked()
{
    QString fileLocation = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        fileLocationTemp,
                                                        tr("LooseChange Files (*.json);;All Files (*.* *"));
    cachedData->WriteFile(fileLocation);
    cachedData->ReadFile(fileLocation);
    rawView->Load();
}

void LooseChangePresenter::EnableSaveButton()
{

    ui->toolButtonSave->setEnabled(true);
}

void LooseChangePresenter::DisableSaveButton()
{
    ui->toolButtonSave->setEnabled(false);
}









