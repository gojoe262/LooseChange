#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <QCloseEvent>
#include <Data/Cache/CachedData.h>
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <UI/Presenter/RawViewPresenter.h>
#include <UI/Presenter/EditCategoriesPresenter.h>
#include <Data/FileAccess/FileAccessor.h>

namespace Ui {
class LooseChangePresenter;
}

class LooseChangePresenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit LooseChangePresenter(QWidget *parent = 0);
    ~LooseChangePresenter();

protected:
    void closeEvent(QCloseEvent *event);

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
     * @brief IsTherePendingChanges
     * @return
     */
    bool IsTherePendingChanges();

    /**
     * @brief on_toolButtonShowRawViewPresenter_clicked
     */
    void on_toolButtonShowRawViewPresenter_clicked();

    /**
     * @brief on_actionE_xit_triggered - Closes the program
     */
    void on_actionE_xit_triggered();

    /**
     * @brief on_toolButtonAddTransaction_clicked - Opens the add transaction window
     */
    void on_toolButtonAddTransaction_clicked();

    /**
     * @brief on_actionAdd_Transaction_triggered - Opens the add transaction window
     */
    void on_actionAdd_Transaction_triggered();

private:
    /**
     * @brief Open - Open a file and load it to cachedData
     */
    void Open();

    /**
     * @brief Save - Save the data in cachedData to a JSON file
     * @return True if saved, false if not saved.
     */
    bool Save();

    /**
     * @brief TryClose - Try to close the program. Checks if there are
     * pending changes.
     */
    bool TryClose();

    /**
     * @brief RefreshAllViews - Forces Views to refresh (pull data from the cached Data).
     */
    void RefreshAllViews();

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
     * @brief fileAccessor - Used to access the file (read and write)
     */
    FileAccessor *fileAccessor;

    /**
     * @brief fileLocationTemp - Stores the file location.
     */
    QString fileLocationTemp;

    /**
     * @brief pendingChanges
     */
    bool pendingChanges;
};

#endif // LOOSECHANGEPRESENTER_H
