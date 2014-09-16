#include "LooseChangePresenter.h"
#include "ui_loosechangepresenter.h"

#include <QFileDialog>
#include <Utility/FileDialog.h>

LooseChangePresenter::LooseChangePresenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LooseChangePresenter)
{
    ui->setupUi(this);
    ui->mainToolBar->addWidget(ui->toolButtonOpen);
    ui->mainToolBar->addWidget(ui->toolButtonSave);
   /// http://iconsetc.com/icon/bfa_folder-open/?style=simple-black


    tableModel = new TableModel(this);

    ui->centralWidget = ui->tabWidget;


}

LooseChangePresenter::~LooseChangePresenter()
{
    delete tableModel;
    delete ui;
}



void LooseChangePresenter::on_toolButtonOpen_clicked()
{
    QString fileLocation = FileDialog::ShowOpenFileDialog(this);

    QList<LooseChangeDTO> dtoList = looseChangeDAO.ReadFile(fileLocation);
    cachedDtoList = CachedDTOList(dtoList);

    delete tableModel;
    tableModel = new TableModel(cachedDtoList.GetDtoList(), this);

    ui->tableView->setModel(tableModel);
}

void LooseChangePresenter::on_toolButtonSave_clicked()
{
    QString fileLocation = FileDialog::ShowSaveFileDialog(this);
    looseChangeDAO.WriteFile(fileLocation, cachedDtoList.GetDtoList());
}

void LooseChangePresenter::on_tableView_clicked(const QModelIndex &index)
{
    if(index.row() >= 0)
    {
        int selectedId = index.sibling(index.row(),0).data().toInt();
        LooseChangeDTO selectedDto = cachedDtoList.GetDTO(selectedId);
        ui->lineEditAmount->setText(QString::number(selectedDto.amount));
        ui->lineEditId->setText(QString::number(selectedDto.id));
    }
    else
    {
        ui->lineEditAmount->setText("");
        ui->lineEditId->setText("");
    }
}


