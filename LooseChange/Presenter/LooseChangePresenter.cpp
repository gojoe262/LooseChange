#include "LooseChangePresenter.h"
#include "ui_loosechangepresenter.h"

LooseChangePresenter::LooseChangePresenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LooseChangePresenter)
{
    ui->setupUi(this);
}

LooseChangePresenter::~LooseChangePresenter()
{
    delete ui;
}

void LooseChangePresenter::on_pushButtonOpenFile_clicked()
{
    QString file = looseChangeDAO.FetchFileLocation(this);
    looseChangeDAO.ReadFile(file);

}
