#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <DataAccess/LooseChangeDAO.h>
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <Presenter/RawViewPresenter.h>

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
    /**
     * @brief on_toolButtonOpen_clicked - Opens the open file dialog.
     * Used to open a LooseChange file
     */
    void on_toolButtonOpen_clicked();

    /**
     * @brief on_toolButtonSave_clicked - Opens the save file dialog.
     * Used to save to a LooseChange File.
     */
    void on_toolButtonSave_clicked();

    /**
     * @brief SaveButtonEnabled - Enables/Disables the Save button.
     * @param enabled
     */
    void SaveButtonEnabled(bool enabled);


private:
    Ui::LooseChangePresenter *ui;

    LooseChangeDAO looseChangeDAO;
    RawViewPresenter *rawView;

    QString fileLocTemp = "";


};

#endif // LOOSECHANGEPRESENTER_H
