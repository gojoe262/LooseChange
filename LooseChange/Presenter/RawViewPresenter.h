#ifndef RAWVIEWPRESENTER_H
#define RAWVIEWPRESENTER_H

#include <DAO/LooseChangeDAO.h>
#include <QTableWidget>

class RawViewPresenter : public QObject
{
    Q_OBJECT
public:
    RawViewPresenter();
    RawViewPresenter(QTableWidget *tableWidget, LooseChangeDAO *inDAO);

    void Load();

private:
    QTableWidget *table;
    LooseChangeDAO *dao;

private slots:
    void AmountValueChanged(double value, QModelIndex index);
};

#endif // RAWVIEWPRESENTER_H
