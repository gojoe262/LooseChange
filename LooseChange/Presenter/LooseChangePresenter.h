#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <DAO/LooseChangeDAO.h>
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <Presenter/RawViewPresenter.h>

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


private:
    QList<LooseChangeDTO> GetDataFromTableWidgetRawView();
    void Update(QModelIndex index, QDate date);
    Ui::LooseChangePresenter *ui;

    LooseChangeDAO looseChangeDAO;

    RawViewPresenter rawView;


};

#endif // LOOSECHANGEPRESENTER_H
