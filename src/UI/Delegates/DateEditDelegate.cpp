#include "DateEditDelegate.h"
#include <QDateEdit>
#include <QtGui>

DateEditDelegate::DateEditDelegate(QObject *parent)
    :QItemDelegate(parent)
{
}

DateEditDelegate::~DateEditDelegate()
{
}

QWidget *DateEditDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QDateEdit *editor = new QDateEdit(parent);
    editor->setCalendarPopup(true);
    return editor;
}


void DateEditDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    QDate value = index.model()->data(index, Qt::EditRole).toDate();

    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    dateEdit->setCalendarPopup(true);
    dateEdit->setDate(value);
}

void DateEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
    dateEdit->interpretText();
    QDate value = dateEdit->date();

    model->setData(index, value, Qt::EditRole);
}

void DateEditDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
