#ifndef PENDINGCHANGESWARNINGPRESENTER_H
#define PENDINGCHANGESWARNINGPRESENTER_H

#include <QDialog>
/**
 * This is a dialog box that asks the user if they
 * want to save their unsaved changes.
 */
namespace Ui {
class PendingChangesWarningPresenter;
}

class PendingChangesWarningPresenter : public QDialog
{
    Q_OBJECT

public:
    explicit PendingChangesWarningPresenter(QString fileName, QWidget *parent = 0);
    ~PendingChangesWarningPresenter();

private slots:
    void on_pushButtonYes_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonNo_clicked();

private:
    Ui::PendingChangesWarningPresenter *ui;
};

#endif // PENDINGCHANGESWARNINGPRESENTER_H
