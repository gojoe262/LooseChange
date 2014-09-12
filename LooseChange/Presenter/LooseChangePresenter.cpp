#include "LooseChangePresenter.h"
#include "ui_loosechangepresenter.h"

#include <QFileDialog>
#include <Utility/FileDialog.h>

LooseChangePresenter::LooseChangePresenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LooseChangePresenter)
{
    ui->setupUi(this);
    ui->mainToolBar->addWidget(ui->toolButtonOpen);
    ui->mainToolBar->addWidget(ui->toolButtonSave);
   /// http://iconsetc.com/icon/bfa_folder-open/?style=simple-black


    tableModel = new TableModel(this);










}

LooseChangePresenter::~LooseChangePresenter()
{
    delete tableModel;
    delete ui;
}



void LooseChangePresenter::on_toolButtonOpen_clicked()
{
    QString fileLocation = FileDialog::ShowOpenFileDialog(this);
    dtoList = looseChangeDAO.ReadFile(fileLocation);

    delete tableModel;
    tableModel = new TableModel(dtoList, this);

    ui->tableView->setModel(tableModel);
}

void LooseChangePresenter::on_toolButtonSave_clicked()
{
    QString fileLocation = FileDialog::ShowSaveFileDialog(this);
    looseChangeDAO.WriteFile(fileLocation, dtoList);
}
