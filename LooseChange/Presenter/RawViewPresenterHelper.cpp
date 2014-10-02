#include "RawViewPresenterHelper.h"
#include <Delegates/DateEditDelegate.h>
#include <Delegates/DoubleSpinBoxDelegate.h>
RawViewPresenterHelper::RawViewPresenterHelper()
{
}

RawViewPresenterHelper::RawViewPresenterHelper(QTableWidget *tableWidget)
{
    table = tableWidget;
}


void RawViewPresenterHelper::Load(LooseChangeDAO dao)
{

    QList<LooseChangeDTO> dtoList = dao.GetList();
    int count = dtoList.count();


    table->clear();
    table->setColumnCount(6);
    table->setRowCount(count);





    table->setItemDelegateForColumn(1, new DateEditDelegate());
    table->setItemDelegateForColumn(2, new DoubleSpinBoxDelegate());

    for(int i = 0; i < count; i++)
    {
        LooseChangeDTO dto = dtoList.at(i);
        QModelIndex index;
        /// Column 0
       /// ui->tableWidgetRawView->verticalHeaderItem(i)->setText(QString::number(dto.id));


        /// Column 1
        index = table->model()->index(i, 1, QModelIndex());
        table->model()->setData(index, QVariant(dto.date));



        /// Column 2
        index = table->model()->index(i, 2, QModelIndex());
        table->model()->setData(index, QVariant(dto.amount));

        /// Column 3
        /// Column 4











//        ui->tableWidgetRawView->setItem(i,2, new QTableWidgetItem(QString::number(dto.amount)));
//        ui->tableWidgetRawView->setItem(i,3,new QTableWidgetItem(TransationTypeHelper::ToString(dto.transactionType)));
//        ui->tableWidgetRawView->setItem(i, 4, new QTableWidgetItem(dto.comment));
//        ui->tableWidgetRawView->setItem(i,5, new QTableWidgetItem(CategoryHelper::ToQString(dto.category)));
        double amount = table->model()->data(ui->tableWidgetRawView->model()->index(i,2)).toDouble();
        qDebug() << amount;
}
