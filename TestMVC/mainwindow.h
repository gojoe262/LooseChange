#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <testdto.h>
#include <mytablemodel.h>
#include <spinboxdelegate.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonAdd_clicked();

private:
    Ui::MainWindow *ui;
    QList<TestDto> testDtoList;
    MyTableModel *model;
    SpinboxDelegate *spinboxDelegate;
};

#endif // MAINWINDOW_H
