#include "CommentLineEditDelegate.h"

CommentLineEditDelegate::CommentLineEditDelegate(QObject *parent)
    :QItemDelegate(parent)
{
}

CommentLineEditDelegate::~CommentLineEditDelegate()
{
}

QWidget *CommentLineEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    return editor;
}

void CommentLineEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index)
{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    QString value = index.model()->data(index, Qt::EditRole).toString();

    lineEdit->setText(value);
}

void CommentLineEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    QString value = lineEdit->text();

    model->setData(index, value, Qt::EditRole);

    emit ValueChanged(value, index);
}

void CommentLineEditDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
