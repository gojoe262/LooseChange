#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    testDtoList.append(TestDto(1, 10));
    testDtoList.append(TestDto(2, 20));
    testDtoList.append(TestDto(3, 30));
    testDtoList.append(TestDto(4, 40));
    testDtoList.append(TestDto(5, 50));

    model = new MyTableModel(&testDtoList, this);
    spinboxDelegate = new SpinboxDelegate(this);


    ui->tableView->setModel(model);
    ui->tableView->setItemDelegateForColumn(1, spinboxDelegate);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked()
{
    model->layoutAboutToBeChanged();
    testDtoList.append(TestDto(5,50));
    model->layoutChanged();
}
