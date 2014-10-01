#ifndef DATEEDITDELEGATE_H
#define DATEEDITDELEGATE_H

#include <QItemDelegate>
#include <QDate>
class DateEditDelegate : public QItemDelegate
{
public:
    DateEditDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;


    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:
    void DataChanged(QModelIndex index, QDate date);


};

#endif // DATEEDITDELEGATE_H
