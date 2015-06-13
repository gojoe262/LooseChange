#include "PendingChangesWarningPresenter.h"
#include "ui_PendingChangesWarningPresenter.h"
#include <QMessageBox>

PendingChangesWarningPresenter::PendingChangesWarningPresenter(QString fileName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PendingChangesWarningPresenter)
{
    ui->setupUi(this);
    if(fileName.trimmed() != "")
        ui->labelMessage->setText("There are unsaved changes.\n\nSave changes to '" + fileName +"'?");
    else
        ui->labelMessage->setText("There are unsaved changes.\n\nSave changes?");
}

PendingChangesWarningPresenter::~PendingChangesWarningPresenter()
{
    delete ui;
}

void PendingChangesWarningPresenter::on_pushButtonYes_clicked()
{
    QDialog::done(QMessageBox::Yes);
}

void PendingChangesWarningPresenter::on_pushButtonCancel_clicked()
{
    QDialog::done(QMessageBox::Cancel);
}

void PendingChangesWarningPresenter::on_pushButtonNo_clicked()
{
    QDialog::done(QMessageBox::No);
}
