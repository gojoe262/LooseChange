#include "mytablemodel.h"

MyTableModel::MyTableModel(QList<TestDto> * inTestDtoList,QObject * parent)
    : QAbstractTableModel(parent)
{
    testDtoList = inTestDtoList;
}

MyTableModel::~MyTableModel()
{

}

int MyTableModel::rowCount(const QModelIndex &index) const
{
    return testDtoList->count();
}

int MyTableModel::columnCount(const QModelIndex &index) const
{
    return 2;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if(testDtoList->isEmpty())
        return QVariant();

    if(!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if(index.column() == 0)
            return testDtoList->at(index.row()).Id;
        if(index.column() == 1)
            return testDtoList->at(index.row()).value;
    }
    return QVariant();
}


bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        int id = data(this->index(index.row(),0)).toInt();
        int count = testDtoList->count();
        for(int i = 0; i < count; i++)
        {
            if(testDtoList->at(i).Id == id)
            {
                if(index.column() == 0)
                {
                    return false;
                }
                else if (index.column() == 1)
                {
                    testDtoList->operator [](i).value = value.toInt();
                    emit(dataChanged(index, index));
                    return true;
                }
            }
        }

    }
    return false;
}


Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
