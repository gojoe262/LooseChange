#include "LooseChangePresenter.h"
#include "ui_loosechangepresenter.h"

#include<QDebug>

#include <QFileDialog>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <Utility/FileDialog.h>
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
    ui->tableWidgetRawView->setEditTriggers(QAbstractItemView::DoubleClicked);
    LoadDataToTableWidgetRawView();


}

LooseChangePresenter::~LooseChangePresenter()
{
    delete ui;
}



void LooseChangePresenter::on_toolButtonOpen_clicked()
{
    QString fileLocation = FileDialog::ShowOpenFileDialog(this);

    looseChangeDAO.ReadFile(fileLocation);

    ui->tableWidgetRawView->clear();
    LoadDataToTableWidgetRawView();
}

void LooseChangePresenter::on_toolButtonSave_clicked()
{
    QString fileLocation = FileDialog::ShowSaveFileDialog(this);
    looseChangeDAO.WriteFile(fileLocation);
}


void LooseChangePresenter::LoadDataToTableWidgetRawView()
{
    QList<LooseChangeDTO> dtoList = looseChangeDAO.GetList();
    int count = dtoList.count();

    ui->tableWidgetRawView->clear();
    ui->tableWidgetRawView->setColumnCount(6);
    ui->tableWidgetRawView->setRowCount(count);

    ui->tableWidgetRawView->setItemDelegateForColumn(1, new DateEditDelegate());
    ui->tableWidgetRawView->setItemDelegateForColumn(2, new DoubleSpinBoxDelegate());

    for(int i = 0; i < count; i++)
    {
        LooseChangeDTO dto = dtoList.at(i);
        QModelIndex index;
        /// Column 0
       /// ui->tableWidgetRawView->verticalHeaderItem(i)->setText(QString::number(dto.id));

        /// Column 1
        index = ui->tableWidgetRawView->model()->index(i, 1, QModelIndex());
        ui->tableWidgetRawView->model()->setData(index, QVariant(dto.date));



        /// Column 2
        index = ui->tableWidgetRawView->model()->index(i, 2, QModelIndex());
        ui->tableWidgetRawView->model()->setData(index, QVariant(dto.amount));

        /// Column 3
        /// Column 4











//        ui->tableWidgetRawView->setItem(i,2, new QTableWidgetItem(QString::number(dto.amount)));
//        ui->tableWidgetRawView->setItem(i,3,new QTableWidgetItem(TransationTypeHelper::ToString(dto.transactionType)));
//        ui->tableWidgetRawView->setItem(i, 4, new QTableWidgetItem(dto.comment));
//        ui->tableWidgetRawView->setItem(i,5, new QTableWidgetItem(CategoryHelper::ToQString(dto.category)));
        double amount = ui->tableWidgetRawView->model()->data(ui->tableWidgetRawView->model()->index(i,2)).toDouble();
        qDebug() << amount;
    }



}

QList<LooseChangeDTO> LooseChangePresenter::GetDataFromTableWidgetRawView()
{
    QList<LooseChangeDTO> dtoList;
    int count = ui->tableWidgetRawView->rowCount();
    for(int i = 0; i < count; i++)
    {
        QDate date = ((QDateEdit*)ui->tableWidgetRawView->cellWidget(i,1))->date();
    }
}






