#include "spinboxdelegate.h"

#include <QSpinBox>

SpinboxDelegate::SpinboxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

SpinboxDelegate::~SpinboxDelegate()
{

}

QWidget* SpinboxDelegate::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &option,
                                       const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    return editor;
}

void SpinboxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
//    spinBox->setMaximum(999999);
//    spinBox->setMinimum(0);
    spinBox->setSingleStep(1);
    spinBox->setValue(value);
}

void SpinboxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}

void SpinboxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

