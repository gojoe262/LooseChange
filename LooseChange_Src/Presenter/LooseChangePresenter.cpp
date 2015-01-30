#include "LooseChangePresenter.h"
#include "ui_LooseChangePresenter.h"

#include <QDebug>

#include <QFileDialog>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <Utility/TransactionType.h>
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

    /// Initialize Presenters
    rawView = new RawViewPresenter(ui->tableViewRawView, &cachedData, this);

    /// SLOTS / SIGNALS
    connect(rawView, SIGNAL(DataChanged()), this, SLOT(EnableSave()));

    DisableSave(); //Disables saves when first loading.

    rawView->Load();


}

LooseChangePresenter::~LooseChangePresenter()
{
    delete rawView;
    delete ui;

}

void LooseChangePresenter::Open()
{
    QString fileLocation = QFileDialog::getOpenFileName(this, tr("Open File"), "./",
                                                        tr("LooseChange Files (*.json);;All Files (*.* *"));
    if(fileLocation != "")
    {
        cachedData.ReadFile(fileLocation);
        rawView->Load();
        fileLocationTemp = fileLocation;
        DisableSave();
    }
}

void LooseChangePresenter::Save()
{
    QString fileLocation = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        fileLocationTemp,
                                                        tr("LooseChange Files (*.json);;All Files (*.* *"));
    cachedData.WriteFile(fileLocation);
    cachedData.ReadFile(fileLocation);
    rawView->Load();
    DisableSave();
}

void LooseChangePresenter::on_toolButtonOpen_clicked()
{
    Open();
}

void LooseChangePresenter::on_toolButtonSave_clicked()
{
    Save();
}

void LooseChangePresenter::on_actionOpen_triggered()
{
    Open();
}

void LooseChangePresenter::on_actionSave_triggered()
{
    Save();
}


void LooseChangePresenter::EnableSave()
{
    ui->actionSave->setEnabled(true);
    ui->toolButtonSave->setEnabled(true);
}

void LooseChangePresenter::DisableSave()
{
    ui->actionSave->setEnabled(false);
    ui->toolButtonSave->setEnabled(false);
}


void LooseChangePresenter::on_actionEdit_Categories_triggered()
{
    CachedData tempCachedData = cachedData;



    EditCategoriesPresenter *e = new EditCategoriesPresenter(&tempCachedData, this);

    int result = e->exec();

    if(result == QDialog::Accepted)
    {
        cachedData = tempCachedData;
        this->EnableSave();
    }
}
