#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <DAO/LooseChangeDAO.h>
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <Model/TableModel.h>
#include <DTO/CachedDTOList.h>

namespace Ui {
class LooseChangePresenter;
}

class LooseChangePresenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit LooseChangePresenter(QWidget *parent = 0);
    ~LooseChangePresenter();

private slots:
    void on_toolButtonOpen_clicked();

    void on_toolButtonSave_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::LooseChangePresenter *ui;

    LooseChangeDAO looseChangeDAO;

    CachedDTOList cachedDtoList;
    //QList<LooseChangeDTO> dtoList;
    TableModel *tableModel;
};

#endif // LOOSECHANGEPRESENTER_H
