#ifndef CATEGORYCOMBOBOXDELEGATE_H
#define CATEGORYCOMBOBOXDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QComboBox>
#include <Data/DAO/CategoryDAO.h>
class CategoryComboBoxDelegate : public QItemDelegate
{
     Q_OBJECT

public:
    CategoryComboBoxDelegate(CategoryDAO *inCategoryDAOPointer, QObject *parent = 0);
    ~CategoryComboBoxDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;


    void setEditorData(QWidget *editor, const QModelIndex &index); //const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:
    void AddCategoryRequested(QModelIndex index) const;

private:
    CategoryDAO *categoryDAOPointer;
};
#endif // CATEGORYCOMBOBOXDELEGATE_H
