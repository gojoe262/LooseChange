#include "ComboBoxDelegate.h"

#include <Utility/TransactionType.h>

ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
    :QItemDelegate(parent)
{
}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox *editor = new QComboBox(parent);

    editor->addItem(TransactionTypeHelper::ToString(OUT),OUT);
    editor->addItem(TransactionTypeHelper::ToString(IN), IN);
    return editor;
}


//void ComboBoxDelegate::setEditorData(QWidget *editor,
//                                     const QModelIndex &index) //const
//{
//    QComboBox *comboBox = static_cast<QComboBox*>(editor);
//    TransactionType value = (TransactionType)index.model()->data(index, Qt::EditRole).toInt();

//    prevSelected = (int)value;
//    comboBox->setCurrentIndex(comboBox->findData(value));
//}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    TransactionType value = (TransactionType)comboBox->currentData().toInt();//TransactionType)index.model()->data(index, Qt::EditRole).toInt();

    model->setData(index, TransactionTypeHelper::ToString(value), Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
