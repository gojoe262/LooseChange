#include "RawViewTableModel.h"

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
        if(index.column() == 0)
            return transactionDAO->GetTransactionAt(index.row()).id;
        if(index.column() == 1)
            return transactionDAO->GetTransactionAt(index.row()).date;
        if(index.column() == 2)
            return transactionDAO->GetTransactionAt(index.row()).amount;
        if(index.column() == 3)
            return transactionDAO->GetTransactionAt(index.row()).transactionType;
        if(index.column() == 4)
            return transactionDAO->GetTransactionAt(index.row()).categoryId;
        if(index.column() == 5)
            return transactionDAO->GetTransactionAt(index.row()).comment;
    }

    return QVariant();
}

bool RawViewTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && Qt::EditRole == role)
    {
        int id = data(this->index(index.row(), 0)).toInt();
        bool changesMade = false;




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
            changesMade = transactionDAO->UpdateCategory(id, value.toInt());
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
        return changesMade;
    }
}

void RawViewTableModel::Refresh()
{
    this->layoutChanged();
}



Qt::ItemFlags RawViewTableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
