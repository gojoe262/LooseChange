#ifndef RAWVIEWWIDGET_H
#define RAWVIEWWIDGET_H

#include <QWidget>
#include <Data/Cache/CachedData.h>
#include <Data/DAO/TransactionDAO.h>
#include <Data/DAO/CategoryDAO.h>
#include <Models/RawViewTableModel.h>
#include <Delegates/DateEditDelegate.h>
#include <Delegates/DoubleSpinBoxDelegate.h>
#include <Delegates/TransactionTypeComboBoxDelegate.h>
#include <Delegates/CategoryComboBoxDelegate.h>
#include <Delegates/CommentLineEditDelegate.h>

namespace Ui {
class RawViewWidget;
}

class RawViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RawViewWidget(CachedData *inCachedDataPtr, QWidget *parent = 0);
    ~RawViewWidget();

    void Load();

private slots:
    void MarkDirty();

signals:
    void DataChanged();

private:
    Ui::RawViewWidget *ui;

    RawViewTableModel *model;

    TransactionDAO *transactionDAO;
    CategoryDAO *categoryDAO;

    DateEditDelegate *dateEdit;
    DoubleSpinBoxDelegate *doubleSpinBox;
    TransactionTypeComboBoxDelegate *transactionTypeComboBox;
    CategoryComboBoxDelegate *categoryComboBox;
    CommentLineEditDelegate *commentLineEdit;
};

#endif // RAWVIEWWIDGET_H
