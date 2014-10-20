#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QComboBox>
#include <Utility/TransactionType.h>

class ComboBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ComboBoxDelegate(QObject *parent = 0);
    ~ComboBoxDelegate();

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
#endif // COMBOBOXDELEGATE_H
