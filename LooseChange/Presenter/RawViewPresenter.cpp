#include "RawViewPresenter.h"
#include <Delegates/DateEditDelegate.h>
#include <Delegates/DoubleSpinBoxDelegate.h>
#include <Delegates/ComboBoxDelegate.h>

RawViewPresenter::RawViewPresenter()
{
}

RawViewPresenter::RawViewPresenter(QTableWidget *tableWidget, LooseChangeDAO *inDAO, QWidget *parent) :
    QObject(parent)
{
    table = tableWidget;
    dao = inDAO;
    table->setEditTriggers(QAbstractItemView::CurrentChanged);  
}

RawViewPresenter::~RawViewPresenter()
{
}


void RawViewPresenter::Load()
{
    QList<LooseChangeDTO> dtoList = dao->GetList();
    int count = dtoList.count();

    table->clear();
    table->setColumnCount(6);
    table->setRowCount(count);

    DateEditDelegate *dateEdit = new DateEditDelegate(this);
    DoubleSpinBoxDelegate *doubleSpinBox = new DoubleSpinBoxDelegate(this);
    ComboBoxDelegate *comboBox = new ComboBoxDelegate(this);

    QObject::connect(dateEdit, SIGNAL(ValueChanged(QDate,QModelIndex)), this, SLOT(ChangeDate(QDate,QModelIndex)));
    QObject::connect(doubleSpinBox, SIGNAL(ValueChanged(double,QModelIndex)), this, SLOT(ChangeAmount(double,QModelIndex)));
    QObject::connect(comboBox, SIGNAL(ValueChanged(TransactionType,QModelIndex)), this, SLOT(ChangeTransactionType(TransactionType, QModelIndex)));

    table->setItemDelegateForColumn(1, dateEdit);
    table->setItemDelegateForColumn(2, doubleSpinBox);
    table->setItemDelegateForColumn(3, comboBox);


    ///ui->tableWidgetRawView->verticalHeaderItem(i)->setText(QString::number(dto.id));
    for(int i = 0; i < count; i++)
    {
        LooseChangeDTO dto = dtoList.at(i);
        QModelIndex index;
        /// Column 0 - ID
        table->setItem(i,0,new QTableWidgetItem(QString::number(dto.id)));

        /// Column 1 - DATE
        index = table->model()->index(i, 1, QModelIndex());
        table->model()->setData(index, QVariant(dto.date));

        /// Column 2 - AMOUNT
        index = table->model()->index(i, 2, QModelIndex());
        table->model()->setData(index, QVariant(dto.amount));

        /// Column 3 - TRANSACTION TYPE
        index = table->model()->index(i, 3, QModelIndex());
        table->model()->setData(index, QVariant(TransactionTypeHelper::ToString(dto.transactionType)));

        /// Column 4

//        ui->tableWidgetRawView->setItem(i,2, new QTableWidgetItem(QString::number(dto.amount)));
//        ui->tableWidgetRawView->setItem(i,3,new QTableWidgetItem(TransationTypeHelper::ToString(dto.transactionType)));
//        ui->tableWidgetRawView->setItem(i, 4, new QTableWidgetItem(dto.comment));
//        ui->tableWidgetRawView->setItem(i,5, new QTableWidgetItem(CategoryHelper::ToQString(dto.category)));
//        double amount = table->model()->data(table->model()->index(i,2)).toDouble();
//        qDebug() << amount;
    }
    table->hideColumn(0);
}

int RawViewPresenter::GetIdFromModelIndex(QModelIndex index) const
{
   return table->model()->data(table->model()->index(index.row(),0)).toInt();
}

void RawViewPresenter::ChangeAmount(double value, QModelIndex index)
{ 
    dao->UpdateAmount(GetIdFromModelIndex(index), value);
}

void RawViewPresenter::ChangeDate(QDate date, QModelIndex index)
{
    dao->UpdateDate(GetIdFromModelIndex(index), date);
}

void RawViewPresenter::ChangeTransactionType(TransactionType type, QModelIndex index)
{
    dao->UpdateTransactionType(GetIdFromModelIndex(index), type);
}




