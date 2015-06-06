#include "LooseChangePresenter.h"
#include "ui_LooseChangePresenter.h"

#include <QDebug>
#include <QFileDialog>
#include <UI/Presenter/AddTransactionPresenter.h>
#include <UI/Presenter/PendingChangesWarningPresenter.h>

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
    ui->mainToolBar->addWidget(ui->toolButtonAddTransaction);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(ui->toolButtonShowRawViewPresenter);
    ui->toolButtonShowRawViewPresenter->setCheckable(true);

    /// Initialize the FileAccessor
    fileAccessor = new FileAccessor();

    /// Initialize Presenters
    rawView = new RawViewPresenter(&cachedData, this);

    /// SLOTS / SIGNALS
    connect(rawView, SIGNAL(DataChanged()), this, SLOT(EnableSave()));

    /// Hide Presenters
    rawView->hide();

    ///Load Data to Presenters
    RefreshAllViews();

    ///Disables saves when first loading.
    DisableSave();

}

LooseChangePresenter::~LooseChangePresenter()
{
    delete rawView;
    delete ui;

}

void LooseChangePresenter::closeEvent(QCloseEvent *event)
{
    if(TryClose())
        event->accept();
    else
        event->ignore();


}

void LooseChangePresenter::Open()
{
    CachedData temp;
    if(fileAccessor->OpenFile(&temp))
    {
        cachedData.Clear();
        cachedData = temp;
        RefreshAllViews();
        DisableSave();
    }
}

bool LooseChangePresenter::Save()
{
    if(fileAccessor->SaveFile(&cachedData))
    {
        DisableSave();
        return true;
    }
    return false;
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
    this->setWindowTitle("* " + fileAccessor->GetFileName() + " - Loose Change");
}

void LooseChangePresenter::DisableSave()
{
    ui->actionSave->setEnabled(false);
    ui->toolButtonSave->setEnabled(false);
    this->setWindowTitle(fileAccessor->GetFileName() + " - Loose Change");
}

bool LooseChangePresenter::IsTherePendingChanges()
{
    ui->actionSave->isEnabled();
}

void LooseChangePresenter::RefreshAllViews()
{
    rawView->Refresh();
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
    delete e;
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

void LooseChangePresenter::on_toolButtonAddTransaction_clicked()
{
    on_actionAdd_Transaction_triggered();
}

void LooseChangePresenter::on_actionAdd_Transaction_triggered()
{
    CachedData tempCachedData = cachedData;

    AddTransactionPresenter *t = new AddTransactionPresenter(&tempCachedData, this);
    int result = t->exec();

    if(result == QDialog::Accepted)
    {
        cachedData = tempCachedData;
        EnableSave();
        RefreshAllViews();
    }
    delete t;
}

bool LooseChangePresenter::TryClose()
{
    if(IsTherePendingChanges())
    {
        PendingChangesWarningPresenter *warning = new PendingChangesWarningPresenter(fileAccessor->GetFileName(), this);
        int result = warning->exec();
        delete warning;


        if(result == QMessageBox::No)
        {
            return true;
        }
        else if(result == QMessageBox::Yes)
        {
            if(this->Save())
            {
                return true;
            }
            return false;
        }
        else if(result == QMessageBox::Cancel)
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

