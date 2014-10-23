#include "CategoryComboBoxDelegate.h"
#include <QtGui>

CategoryComboBoxDelegate::CategoryComboBoxDelegate(QObject *parent)
    :QItemDelegate(parent)
{
}

CategoryComboBoxDelegate::~CategoryComboBoxDelegate()
{
}

QWidget *CategoryComboBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox *editor = new QComboBox(parent);

    editor->addItem(CategoryHelper::ToString(Other), Other);
    editor->addItem(CategoryHelper::ToString(Groceries), Groceries);
    editor->addItem(CategoryHelper::ToString(Shopping), Shopping);
    editor->addItem(CategoryHelper::ToString(Restaurants), Restaurants);
    editor->addItem(CategoryHelper::ToString(GasTravel), GasTravel);
    editor->addItem(CategoryHelper::ToString(Phone), Phone);

    return editor;
}


void CategoryComboBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) //const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    Category value = (Category)index.model()->data(index, Qt::EditRole).toInt();

    comboBox->setCurrentIndex(comboBox->findData(value));
}

void CategoryComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    Category value = (Category)comboBox->currentData().toInt();

    model->setData(index, CategoryHelper::ToString(value), Qt::EditRole);

    //PUT SIGNAL HERE
    emit ValueChanged(value, index);
}

void CategoryComboBoxDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
