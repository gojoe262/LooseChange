#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QItemDelegate>
#include <QComboBox>
#include <Utility/TransactionType.h>

class ComboBoxDelegate : public QItemDelegate
{
public:
    ComboBoxDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;


    //void setEditorData(QWidget *editor, const QModelIndex &index); //const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    int prevSelected;
};
#endif // COMBOBOXDELEGATE_H
