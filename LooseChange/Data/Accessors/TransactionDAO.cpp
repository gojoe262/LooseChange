#include "TransactionDAO.h"

#include <QTextStream>
#include <QStringList>
#include <QFileDialog>
#include <QObject>
#include <QFile>
#include <Utility/TransactionType.h>
#include <Utility/Categories.h>
#include <Data/FileAccess/FileReader.h>
#include <Data/FileAccess/FileWriter.h>
#include <QMessageBox>

TransactionDAO::TransactionDAO()
{
}

TransactionDAO::TransactionDAO(CachedData *inCachedDataPointer, QWidget *parent) : QObject(parent)
{
    cachedDataPointer = inCachedDataPointer;
}

TransactionDAO::~TransactionDAO()
{
    //cachedDataPointer to be deleted elsewhere because it is passed in.
}

QList<TransactionDTO> TransactionDAO::GetTransactionList()
{
    return cachedDataPointer->GetTransactionList();
}

void TransactionDAO::AddTransaction(TransactionDTO inTransaction)
{
    cachedDataPointer->AddTransaction(inTransaction);
}

void TransactionDAO::UpdateAmount(int id, double amount)
{
    cachedDataPointer->UpdateTransactionAmount(id, amount);
}

void TransactionDAO::UpdateDate(int id, QDate date)
{
    cachedDataPointer->UpdateTransactionDate(id, date);
}

void TransactionDAO::UpdateType(int id, TransactionType type)
{
    cachedDataPointer->UpdateTransactionType(id, type);
}

void TransactionDAO::UpdateComment(int id, QString comment)
{
    cachedDataPointer->UpdateTransactionComment(id, comment);
}
