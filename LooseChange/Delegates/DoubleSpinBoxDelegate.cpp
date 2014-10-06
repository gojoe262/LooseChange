#include "DoubleSpinBoxDelegate.h"
#include <QtGui>

DoubleSpinBoxDelegate::DoubleSpinBoxDelegate(QObject *parent)
    :QItemDelegate(parent)
{
}

QWidget *DoubleSpinBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
    return editor;
}


void DoubleSpinBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    double value = index.model()->data(index, Qt::EditRole).toDouble();

    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->setDecimals(2);
    spinBox->setMaximum(999999999);
    spinBox->setMinimum(0);
    spinBox->setSingleStep(0.50);
    spinBox->setValue(value);
}

void DoubleSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->interpretText();
    double value = spinBox->value();

    model->setData(index, value, Qt::EditRole);

    //PUT SIGNAL HERE
    emit this->ValueChanged(value, index);


}

void DoubleSpinBoxDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}







