#ifndef EDITCATEGORIESTABLEMODEL_H
#define EDITCATEGORIESTABLEMODEL_H

#include <QAbstractTableModel>
#include <Data/DAO/CategoryDAO.h>

class EditCategoriesTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    EditCategoriesTableModel(CategoryDAO *inCategoryDAOPointer, QObject *parent = 0);

    ~EditCategoriesTableModel();


   int rowCount(const QModelIndex &index) const;

   int columnCount(const QModelIndex &index) const;

   QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

   bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);

   Qt::ItemFlags flags(const QModelIndex &index) const;

   /**
    * @brief Refresh - Forces a re-retreive from the cached data
    */
   void Refresh();

private:
    CategoryDAO *categoryDAO;

};

#endif // EDITCATEGORIESTABLEMODEL_H
