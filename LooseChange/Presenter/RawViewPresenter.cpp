#include "RawViewPresenter.h"
#include <Delegates/DateEditDelegate.h>
#include <Delegates/DoubleSpinBoxDelegate.h>
#include <Delegates/ComboBoxDelegate.h>

RawViewPresenter::RawViewPresenter()
{
}

RawViewPresenter::RawViewPresenter(QTableWidget *tableWidget, LooseChangeDAO *inDAO)
{
    table = tableWidget;
    dao = inDAO;
    table->setEditTriggers(QAbstractItemView::CurrentChanged);  
}


void RawViewPresenter::Load()
{
    QList<LooseChangeDTO> dtoList = dao->GetList();
    int count = dtoList.count();

    table->clear();
    table->setColumnCount(6);
    table->setRowCount(count);

    DoubleSpinBoxDelegate *d = new DoubleSpinBoxDelegate();

    QObject::connect(d, SIGNAL(ValueChanged(double,QModelIndex)), this, SLOT(AmountValueChanged(double, QModelIndex)));

    table->setItemDelegateForColumn(1, new DateEditDelegate());
    table->setItemDelegateForColumn(2, d);
    table->setItemDelegateForColumn(3, new ComboBoxDelegate());

    for(int i = 0; i < count; i++)
    {
        LooseChangeDTO dto = dtoList.at(i);
        QModelIndex index;
        /// Column 0
        ///ui->tableWidgetRawView->verticalHeaderItem(i)->setText(QString::number(dto.id));
        table->setItem(i,0,new QTableWidgetItem(QString::number(dto.id)));

        /// Column 1
        index = table->model()->index(i, 1, QModelIndex());
        table->model()->setData(index, QVariant(dto.date));

        /// Column 2
        index = table->model()->index(i, 2, QModelIndex());
        table->model()->setData(index, QVariant(dto.amount));

        /// Column 3
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

void RawViewPresenter::AmountValueChanged(double value, QModelIndex index)
{
    int id = table->model()->data(table->model()->index(index.row(),0)).toInt();
    dao->UpdateAmount(id, value);

}
