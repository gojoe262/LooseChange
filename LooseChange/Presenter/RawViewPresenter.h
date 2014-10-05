#ifndef RAWVIEWPRESENTER_H
#define RAWVIEWPRESENTER_H

#include <DAO/LooseChangeDAO.h>
#include <QTableWidget>

class RawViewPresenter
{
public:
    RawViewPresenter();
    RawViewPresenter(QTableWidget *tableWidget, LooseChangeDAO *inDAO);

    void Load(LooseChangeDAO dao);

private:
    QTableWidget *table;
    LooseChangeDAO *dao;

private slots:
    void AmountValueChanged(double* value);
};

#endif // RAWVIEWPRESENTER_H
