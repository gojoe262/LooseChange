#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <testdto.h>
#include <QAbstractTableModel>
///http://qt-project.org/doc/qt-4.8/qabstracttablemodel.html

class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyTableModel(QList<TestDto> * inTestDtoList ,QObject * parent = 0);
    ~MyTableModel();

    int rowCount(const QModelIndex &index) const;

    int columnCount(const QModelIndex &index) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);

    Qt::ItemFlags flags(const QModelIndex &index) const;


private:
    QList<TestDto> *testDtoList;
};

#endif // MYTABLEMODEL_H


