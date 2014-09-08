#include "TableModel.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}


TableModel::TableModel(QList<LooseChangeDTO> inList, QObject *parent) :
    QAbstractTableModel(parent)
{
    dtoList = inList;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dtoList.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;   //Current no. of properties in LooseChangeDTO
}

QVariant TableModel::data(const QModelIndex &index, int role) const
 {
     if (!index.isValid())
         return QVariant();

     if (index.row() >= dtoList.size() || index.row() < 0)
         return QVariant();

     if (role == Qt::DisplayRole) {
         LooseChangeDTO dto = dtoList.at(index.row());

         if (index.column() == 0)
             return dto.date;
         else if (index.column() == 1)
             return dto.amount;
         else if (index.column() == 2)
             return dto.transactionType;
         else if (index.column() == 3)
             return CategoryHelper::ToQString(dto.category);
         else if (index.column() == 4)
             return dto.comment;
     }
     return QVariant();
 }

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
 {
     if (role != Qt::DisplayRole)
         return QVariant();

     if (orientation == Qt::Horizontal) {
         switch (section) {
             case 0:
                 return tr("Date");
             case 1:
                 return tr("Amount");
             case 2:
                 return tr("Type");
             case 3:
                 return tr("Category");
             case 4:
                 return tr("Comment");
             default:
                 return QVariant();
         }
     }
     return QVariant();
 }
