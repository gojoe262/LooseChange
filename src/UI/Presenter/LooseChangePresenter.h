#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <Data/Cache/CachedData.h>
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <UI/Presenter/RawViewPresenter.h>
#include <UI/Presenter/EditCategoriesPresenter.h>

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
     * @brief on_toolButtonOpen_clicked - Calls Open()
     * This is used by the toolbar
     */
    void on_toolButtonOpen_clicked();

    /**
     * @brief on_toolButtonSave_clicked - Calls Save()
     * This is used by the toolbar
     */
    void on_toolButtonSave_clicked();

    /**
     * @brief on_actionOpen_triggered - Calls Open()
     */
    void on_actionOpen_triggered();

    /**
     * @brief on_actionSave_triggered - Calls Save()
     */
    void on_actionSave_triggered();

    /**
     * @brief on_actionEdit_Categories_triggered
     */
    void on_actionEdit_Categories_triggered();

    /**
     * @brief EnableSave
     */
    void EnableSave();

    /**
     * @brief DisableSave
     */
    void DisableSave();

    /**
     * @brief on_toolButtonShowRawViewPresenter_clicked
     */
    void on_toolButtonShowRawViewPresenter_clicked();

    void on_actionE_xit_triggered();

private:
    /**
     * @brief Open - Open a file and load it to cachedData
     */
    void Open();

    /**
     * @brief Save - Save the data in cachedData to a JSON file
     */
    void Save();

    /**
     * @brief ui
     */
    Ui::LooseChangePresenter *ui;

    /**
     * @brief rawView - Raw View Presenter: Shows cached data in a simple format.
     */
    RawViewPresenter *rawView;

    /**
     * @brief cachedData - Holds the data
     */
    CachedData cachedData;

    /**
     * @brief fileLocationTemp - Stores the file location.
     */
    QString fileLocationTemp;



};

#endif // LOOSECHANGEPRESENTER_H
