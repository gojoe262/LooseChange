#ifndef RAWVIEWPRESENTERHELPER_H
#define RAWVIEWPRESENTERHELPER_H

#include <DAO/LooseChangeDAO.h>
#include <QTableWidget>

class RawViewPresenterHelper
{
public:
    RawViewPresenterHelper();
    RawViewPresenterHelper::RawViewPresenterHelper(QTableWidget *tableWidget);

    void Load(LooseChangeDAO dao);

private:
    QTableWidget *table;
};

#endif // RAWVIEWPRESENTERHELPER_H
