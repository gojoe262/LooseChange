#include "CategoryComboBoxDelegate.h"

#include <QtGui>
#include <QInputDialog>

CategoryComboBoxDelegate::CategoryComboBoxDelegate(QList<CategoryDTO> inCategoryList, QObject *parent)
    :QItemDelegate(parent)
{
    categoryList = inCategoryList;
}

CategoryComboBoxDelegate::~CategoryComboBoxDelegate()
{
}

QWidget *CategoryComboBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox *editor = new QComboBox(parent);

    foreach(CategoryDTO category, categoryList)
    {
        editor->addItem(category.category, QVariant(category.category));
    }
    editor->addItem("*ADD CATEGORY*", QVariant("*ADD CATEGORY*"));

    return editor;
}


void CategoryComboBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) //const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString value = index.model()->data(index, Qt::EditRole).toString();

    comboBox->setCurrentIndex(comboBox->findText(value));
}

void CategoryComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    QString value = comboBox->currentData().toString();
    if(value == "*ADD CATEGORY*")
    {
        emit AddCategoryRequested(index);
        return;
        //PUT SIGNAL HERE???
        //SIGNAL WILL BE CAUGHT BY THE LOOSECHANGEPRESENTER
//        bool ok;
//        QString text = QInputDialog::getText(, tr("Add Category"), tr("New Category:"), QLineEdit::Normal,&ok);
//        if (ok && !text.isEmpty())
//        {
//            categoryList.append(CategoryDTO(text));
//            value = text;
//        }
    }

    model->setData(index, value, Qt::EditRole);

    //PUT SIGNAL HERE
    emit ValueChanged(CategoryDTO(value), index);
}

void CategoryComboBoxDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
