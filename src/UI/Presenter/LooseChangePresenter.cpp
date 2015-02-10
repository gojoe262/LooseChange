#include "LooseChangePresenter.h"
#include "ui_LooseChangePresenter.h"

#include <QDebug>
#include <QFileDialog>


LooseChangePresenter::LooseChangePresenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LooseChangePresenter)
{
    ///Sets up the UI
    ui->setupUi(this);

    ///Add Buttons to the toolbar
    ui->mainToolBar->addWidget(ui->toolButtonOpen);
    ui->mainToolBar->addWidget(ui->toolButtonSave);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(ui->toolButtonShowRawViewPresenter);
    ui->toolButtonShowRawViewPresenter->setCheckable(true);

    /// Initialize Presenters
    rawView = new RawViewPresenter(&cachedData, this);

    /// SLOTS / SIGNALS
    connect(rawView, SIGNAL(DataChanged()), this, SLOT(EnableSave()));

    /// Hide Presenters
    rawView->hide();

    ///Load Data to Presenters
    rawView->RetriveAndLoadCachedData();

    DisableSave(); //Disables saves when first loading.

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
        rawView->RetriveAndLoadCachedData();
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
    rawView->RetriveAndLoadCachedData();
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

void LooseChangePresenter::on_toolButtonShowRawViewPresenter_clicked()
{
    if(ui->toolButtonShowRawViewPresenter->isChecked())
    {
        this->setCentralWidget(rawView);
        rawView->show();
    }
    else
    {
        rawView->hide();
    }
}

void LooseChangePresenter::on_actionE_xit_triggered()
{
    this->close();
}
