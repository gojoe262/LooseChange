#ifndef RAWVIEWPRESENTER_H
#define RAWVIEWPRESENTER_H

#include <DAO/LooseChangeDAO.h>
#include <QTableWidget>

class RawViewPresenter
{
public:
    RawViewPresenter();
    RawViewPresenter(QTableWidget *tableWidget);

    void Load(LooseChangeDAO dao);

private:
    QTableWidget *table;
};

#endif // RAWVIEWPRESENTER_H
