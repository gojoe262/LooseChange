#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <LooseChangeDAO.h>

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
    void on_pushButtonOpenFile_clicked();

private:
    Ui::LooseChangePresenter *ui;

    LooseChangeDAO looseChangeDAO;
};

#endif // LOOSECHANGEPRESENTER_H
