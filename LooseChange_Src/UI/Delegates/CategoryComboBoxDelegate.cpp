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

    return editor;
}


void CategoryComboBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) //const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString categoryId = index.model()->data(index, Qt::EditRole).toString();

    comboBox->setCurrentIndex(comboBox->findData(categoryId));
}

void CategoryComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    QString categoryId = comboBox->currentData().toString();

    model->setData(index, categoryId, Qt::EditRole);
}

void CategoryComboBoxDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
