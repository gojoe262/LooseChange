#include "TransactionTypeComboBoxDelegate.h"

#include <Utility/TransactionType.h>
#include <QtGui>
TransactionTypeComboBoxDelegate::TransactionTypeComboBoxDelegate(QObject *parent)
    :QItemDelegate(parent)
{
}

TransactionTypeComboBoxDelegate::~TransactionTypeComboBoxDelegate()
{
}

QWidget *TransactionTypeComboBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox *editor = new QComboBox(parent);

    editor->addItem(TransactionTypeHelper::ToString(OUT),OUT);
    editor->addItem(TransactionTypeHelper::ToString(IN), IN);
    return editor;
}


void TransactionTypeComboBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) //const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    TransactionType value = (TransactionType)index.model()->data(index, Qt::EditRole).toInt();

    comboBox->setCurrentIndex(comboBox->findData(value));
}

void TransactionTypeComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    TransactionType value = (TransactionType)comboBox->currentData().toInt();

    model->setData(index, value, Qt::EditRole);
}

void TransactionTypeComboBoxDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
