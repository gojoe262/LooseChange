#include "EditCategoriesTableModel.h"

EditCategoriesTableModel::EditCategoriesTableModel(CategoryDAO *inCategoryDAOPointer, QObject *parent)
    : QAbstractTableModel(parent)
{
    categoryDAO = inCategoryDAOPointer;
}

EditCategoriesTableModel::~EditCategoriesTableModel()
{

}

int EditCategoriesTableModel::rowCount(const QModelIndex &index) const
{
    return categoryDAO->Count();
}

int EditCategoriesTableModel::columnCount(const QModelIndex &index) const
{
    return 2;
}

QVariant EditCategoriesTableModel::data(const QModelIndex &index, int role) const
{
    if(categoryDAO->Count() == 0)
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
        {
            return categoryDAO->GetCategories()[index.row()].id;
        }

        if(index.column() == 1)
        {
            return categoryDAO->GetCategories()[index.row()].description;
        }
    }

    return QVariant();
}

bool EditCategoriesTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool changesMade = false;
    if(index.isValid() && Qt::EditRole == role)
    {
        int id = data(this->index(index.row(), 0)).toInt();


        if(index.column() == 1)
        {
            changesMade = categoryDAO->UpdateDescription(id, value.toString());
        }

        if(changesMade)
        {
            emit(dataChanged(index, index));
        }
    }
    return changesMade;
}

void EditCategoriesTableModel::Refresh()
{
    layoutChanged();
}

Qt::ItemFlags EditCategoriesTableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
