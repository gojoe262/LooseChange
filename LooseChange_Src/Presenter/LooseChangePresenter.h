#ifndef LOOSECHANGEPRESENTER_H
#define LOOSECHANGEPRESENTER_H

#include <QMainWindow>
#include <Data/Cache/CachedData.h>
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <Presenter/RawViewPresenter.h>
#include <Presenter/EditCategoriesPresenter.h>

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
    void Open();
    void Save();

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





private:
    Ui::LooseChangePresenter *ui;

    /**
     * @brief rawView - Handles the raw view stuff
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
