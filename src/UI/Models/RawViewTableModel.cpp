#include "RawViewTableModel.h"
#include <QMessageBox>

RawViewTableModel::RawViewTableModel(TransactionDAO *inTransactionDAOPointer, CategoryDAO *inCategoryDAOPointer, QObject *parent)
    : QAbstractTableModel(parent)
{
    transactionDAO = inTransactionDAOPointer;
    categoryDAO = inCategoryDAOPointer;
}

RawViewTableModel::~RawViewTableModel()
{

}

int RawViewTableModel::rowCount(const QModelIndex &index) const
{
    QList<TransactionDTO> list = transactionDAO->GetTransactionList();
    return list.count();
}

int RawViewTableModel::columnCount(const QModelIndex &index) const
{
    return 6;
}

QVariant RawViewTableModel::data(const QModelIndex &index, int role) const
{
    ///This sets the data that is seen in the table view
    if(transactionDAO->GetTransactionList().isEmpty())
    {
        return QVariant();
    }

    if(!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        QList<TransactionDTO> dtoList = transactionDAO->GetTransactionList();
        if(index.column() == 0)
        {
            return dtoList[index.row()].id;
        }

        if(index.column() == 1)
        {
            return dtoList[index.row()].date.toString("ddd, MMM d, yyyy");
        }
        if(index.column() == 2)
        {
            return dtoList[index.row()].amount;
        }
        if(index.column() == 3)
        {
            return TransactionTypeHelper::ToString(dtoList[index.row()].transactionType);
        }
        if(index.column() == 4)
        {
            QString categoryId = dtoList[index.row()].categoryId;
            return categoryDAO->GetCategoryById(categoryId).description;
        }
        if(index.column() == 5)
        {
            return dtoList[index.row()].comment;
        }
    }

    return QVariant();
}

bool RawViewTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool changesMade = false;
    if(index.isValid() && Qt::EditRole == role)
    {
        QString id = data(this->index(index.row(), 0)).toString();

        /// Column 1 - DATE
        if(index.column() == 1)
        {
            changesMade = transactionDAO->UpdateDate(id, value.toDate());
        }
        /// Column 2 - AMOUNT
        else if(index.column() == 2)
        {
            changesMade = transactionDAO->UpdateAmount(id, value.toDouble());
        }
        /// Column 3 - TRANSACTION TYPE
        else if(index.column() == 3)
        {
            changesMade = transactionDAO->UpdateType(id, (TransactionType)value.toInt());
        }
        /// Column 4 - CATEGORY
        else if(index.column() == 4)
        {
            changesMade = transactionDAO->UpdateCategory(id, value.toString());
        }
        /// Column 5 - COMMENT
        else if(index.column() == 5)
        {
            changesMade = transactionDAO->UpdateComment(id, value.toString());
        }


        if(changesMade)
        {
            emit(dataChanged(index, index));
        }
    }
    return changesMade;
}

void RawViewTableModel::Refresh()
{
    layoutChanged();
}

Qt::ItemFlags RawViewTableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void RawViewTableModel::sort(int column, Qt::SortOrder order)
{
    // Order of data should not matter. If it does, then emit the
    // following to show that the data has changed:
    ///emit(dataChanged(QModelIndex(), QModelIndex()));

    /// Column 1 - DATE
    if(column == 1)
    {
        transactionDAO->SortTransactionListByDate(order);
        Refresh();
    }
    /// Column 2 - AMOUNT
    else if(column == 2)
    {
        transactionDAO->SortTransactionListByAmount(order);
        Refresh();
    }
    /// Column 3 - TRANSACTION TYPE
    else if(column == 3)
    {
        transactionDAO->SortTransactionListByTransactionType(order);
        Refresh();
    }
    /// Column 4 - CATEGORY
    else if(column == 4)
    {
        transactionDAO->SortTransactionListByCategory(order);
        Refresh();
    }
    /// Column 5 - COMMENT
    else if(column == 5)
    {
        transactionDAO->SortTransactionListByComment(order);
        Refresh();
    }
}
