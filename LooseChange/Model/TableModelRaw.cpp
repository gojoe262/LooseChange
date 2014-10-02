#include "TableModel.h"

TableModelRaw::TableModelRaw(QObject *parent) :
    QAbstractTableModel(parent)
{
}


TableModelRaw::TableModelRaw(QList<LooseChangeDTO> inList, QObject *parent) :
    QAbstractTableModel(parent)
{
    dtoList = inList;

}

int TableModelRaw::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dtoList.size();
}

int TableModelRaw::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;   //Current no. of properties in LooseChangeDTO
}

QVariant TableModelRaw::data(const QModelIndex &index, int role) const
 {
     if (!index.isValid())
         return QVariant();

     if (index.row() >= dtoList.size() || index.row() < 0)
         return QVariant();

     if (role == Qt::DisplayRole) {
         LooseChangeDTO dto = dtoList.at(index.row());

         if (index.column() == 0)
             return dto.id;
         else if (index.column() == 1)
             return dto.date;
         else if (index.column() == 2)
             return dto.amount;
         else if (index.column() == 3)
             return dto.transactionType;
         else if (index.column() == 4)
             return CategoryHelper::ToQString(dto.category);
         else if (index.column() == 5)
             return dto.comment;
     }
     return QVariant();
 }

QVariant TableModelRaw::headerData(int section, Qt::Orientation orientation, int role) const
 {
     if (role != Qt::DisplayRole)
         return QVariant();

     if (orientation == Qt::Horizontal) {
         switch (section) {
             case 0:
                 return tr("Id");
             case 1:
                 return tr("Date");
             case 2:
                 return tr("Amount");
             case 3:
                 return tr("Type");
             case 4:
                 return tr("Category");
             case 5:
                 return tr("Comment");
             default:
                 return QVariant();
         }
     }
     return QVariant();
 }

Qt::ItemFlags TableModelRaw::flags (const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

//bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if (index.isValid() && role == Qt::EditRole)
//    {
//        int row = index.row();
//        int column = index.column();


//        QPair<QString, QString> p = listOfPairs.value(row);
//        if (index.column() == 0)
//        {

//        }
//        else if (index.column() == 1)
//            p.second = value.toString();
//        else
//            return false;

//        listOfPairs.replace(row, p);
//        emit(dataChanged(index, index));
//        return true;
//    }
//    return false;
//}