#include "CategoryComboBoxDelegate.h"

#include <QtGui>
#include <QInputDialog>

CategoryComboBoxDelegate::CategoryComboBoxDelegate(CategoryDAO *inCategoryDAOPointer, QObject *parent)
    :QItemDelegate(parent)
{
   categoryDAOPointer = inCategoryDAOPointer;
}

CategoryComboBoxDelegate::~CategoryComboBoxDelegate()
{
}

QWidget *CategoryComboBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox *editor = new QComboBox(parent);
    QList<CategoryDTO> categoryList = categoryDAOPointer->GetCategories();
    foreach(CategoryDTO category, categoryList)
    {
        editor->addItem(category.description, QVariant(category.id));
    }
    editor->addItem("*ADD CATEGORY*", QVariant(-1));

    return editor;
}


void CategoryComboBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) //const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    int value = index.model()->data(index, Qt::EditRole).toInt();

    comboBox->setCurrentIndex(comboBox->findData(value));
}

void CategoryComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    int value = comboBox->currentData().toInt();
    if(value == -1)
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

    model->setData(index, categoryDAOPointer->GetDescription(value), Qt::EditRole);
}

void CategoryComboBoxDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
