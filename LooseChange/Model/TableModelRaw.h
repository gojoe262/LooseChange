#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <DTO/LooseChangeDTO.h>

class TableModelRaw : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModelRaw(QObject *parent = 0);

    /**
     * @brief TableModel - creates a Table Model and loads the list to the table
     * @param inList
     * @param parent
     */
    TableModelRaw(QList<LooseChangeDTO> inList, QObject *parent = 0);

    /**
     * @brief rowCount - Get the current row count. (OVERRIDDEN FUNCTION)
     * @param parent
     * @return
     */
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    //bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    /*Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());*/
   // QList<LooseChangeDTO> getList();
};

#endif // TABLEMODEL_H
