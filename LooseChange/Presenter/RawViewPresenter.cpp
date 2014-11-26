#include "RawViewPresenter.h"
#include <Delegates/DateEditDelegate.h>
#include <Delegates/DoubleSpinBoxDelegate.h>
#include <Delegates/TransactionTypeComboBoxDelegate.h>
#include <Delegates/CategoryComboBoxDelegate.h>
#include <Delegates/CommentLineEditDelegate.h>

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
    QList<TransactionDTO> dtoList = dao->GetList();
    int count = dtoList.count();

    table->clear();
    table->setColumnCount(6);
    table->setRowCount(count);

    DateEditDelegate *dateEdit = new DateEditDelegate(this);
    DoubleSpinBoxDelegate *doubleSpinBox = new DoubleSpinBoxDelegate(this);
    TransactionTypeComboBoxDelegate *transactionTypeComboBox = new TransactionTypeComboBoxDelegate(this);
    CategoryComboBoxDelegate *categoryComboBox = new CategoryComboBoxDelegate(this);
    CommentLineEditDelegate *commentLineEdit = new CommentLineEditDelegate(this);


    QObject::connect(dateEdit, SIGNAL(ValueChanged(QDate,QModelIndex)), this, SLOT(ChangeDate(QDate,QModelIndex)));
    QObject::connect(doubleSpinBox, SIGNAL(ValueChanged(double,QModelIndex)), this, SLOT(ChangeAmount(double,QModelIndex)));
    QObject::connect(transactionTypeComboBox, SIGNAL(ValueChanged(TransactionType,QModelIndex)), this, SLOT(ChangeTransactionType(TransactionType, QModelIndex)));
    QObject::connect(categoryComboBox, SIGNAL(ValueChanged(Category,QModelIndex)), this, SLOT(ChangeCategory(Category,QModelIndex)));
    QObject::connect(commentLineEdit, SIGNAL(ValueChanged(QString,QModelIndex)), this, SLOT(ChangeComment(QString, QModelIndex)));

    table->setItemDelegateForColumn(1, dateEdit);
    table->setItemDelegateForColumn(2, doubleSpinBox);
    table->setItemDelegateForColumn(3, transactionTypeComboBox);
    table->setItemDelegateForColumn(4, categoryComboBox);
    table->setItemDelegateForColumn(5, commentLineEdit);



    ///ui->tableWidgetRawView->verticalHeaderItem(i)->setText(QString::number(dto.id));
    for(int i = 0; i < count; i++)
    {
        TransactionDTO dto = dtoList.at(i);
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

        /// Column 4 - CATEGORY
        index = table->model()->index(i, 4, QModelIndex());
        table->model()->setData(index, QVariant(CategoryHelper::ToString(dto.category)));

        /// Column 5 - COMMENT
        index = table->model()->index(i, 5, QModelIndex());
        table->model()->setData(index, QVariant(dto.comment));
    }
    //table->hideColumn(0);
    //table->sortItems(1);
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

void RawViewPresenter::ChangeCategory(Category category, QModelIndex index)
{
    dao->UpdateCategory(GetIdFromModelIndex(index), category);
}

void RawViewPresenter::ChangeComment(QString comment, QModelIndex index)
{
    dao->UpdateComment(GetIdFromModelIndex(index), comment);
}




