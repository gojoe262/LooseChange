#ifndef TRANSACTIONTYPECOMBOBOXDELEGATE_H
#define TRANSACTIONTYPECOMBOBOXDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QComboBox>
#include <Utility/TransactionType.h>

class TransactionTypeComboBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    TransactionTypeComboBoxDelegate(QObject *parent = 0);
    ~TransactionTypeComboBoxDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;


    void setEditorData(QWidget *editor, const QModelIndex &index); //const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
signals:
    void ValueChanged(TransactionType type, QModelIndex index) const;

private:
    int prevSelected;


};
#endif // TRANSACTIONTYPECOMBOBOXDELEGATE_H
