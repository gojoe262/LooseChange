#include "LooseChangePresenter.h"
#include "ui_loosechangepresenter.h"

#include <QFileDialog>

LooseChangePresenter::LooseChangePresenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LooseChangePresenter)
{
    ui->setupUi(this);

    tableModel = new TableModel(this);










}

LooseChangePresenter::~LooseChangePresenter()
{
    delete tableModel;
    delete ui;
}

void LooseChangePresenter::on_pushButtonOpenFile_clicked()
{
    QString fileLocation = QFileDialog::getOpenFileName(this, QObject::tr("Open File"),"",
                            QObject::tr("LooseChange Files (*.lc);;Text Files (*.txt)"));
    delete tableModel;
    tableModel = new TableModel(dtoList = looseChangeDAO.ReadFile(fileLocation), this);

    ui->tableView->setModel(tableModel);

}
