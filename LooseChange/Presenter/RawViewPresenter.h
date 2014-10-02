#ifndef RAWVIEWPRESENTERHELPER_H
#define RAWVIEWPRESENTERHELPER_H

#include <DAO/LooseChangeDAO.h>
#include <QTableWidget>

class RawViewPresenter
{
public:
    RawViewPresenter();
    RawViewPresenter::RawViewPresenter(QTableWidget *tableWidget);

    void Load(LooseChangeDAO dao);

private:
    QTableWidget *table;
};

#endif // RAWVIEWPRESENTERHELPER_H
