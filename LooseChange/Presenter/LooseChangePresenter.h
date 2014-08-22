#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <DAO/LooseChangeDAO.h>

namespace Ui {
class LooseChangePresenter;
}

class LooseChangePresenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit LooseChangePresenter(QWidget *parent = 0);
    ~LooseChangePresenter();

private:
    Ui::LooseChangePresenter *ui;

    LooseChangeDAO looseChangeDAO;
    QList<LooseChangeDTO> dtoList;
};

#endif // LOOSECHANGEPRESENTER_H
