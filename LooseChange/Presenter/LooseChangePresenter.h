#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <DAO/LooseChangeDAO.h>
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <Model/TableModel.h>

namespace Ui {
class LooseChangePresenter;
}

class LooseChangePresenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit LooseChangePresenter(QWidget *parent = 0);
    ~LooseChangePresenter();

    void Initialize ();
    void LoadDataToTableWidgetRawView();
    QList<LooseChangeDTO> GetDataFromTableWidgetRawView();

private slots:
    void on_toolButtonOpen_clicked();

    void on_toolButtonSave_clicked();


private:

    void Update(QModelIndex index, QDate date);
    Ui::LooseChangePresenter *ui;

    TableModelRaw tableModel;
    LooseChangeDAO looseChangeDAO;


};

#endif // LOOSECHANGEPRESENTER_H
