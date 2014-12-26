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

TransactionDTO TransactionDAO::GetTransactionAt(int index)
{
    return cachedDataPointer->GetTransactionList()[index];
}

void TransactionDAO::AddTransaction(TransactionDTO inTransaction)
{
    //GetNextId needs to be made first
    //cachedDataPointer->AddTransaction(inTransaction);
}

bool TransactionDAO::UpdateAmount(int id, double amount)
{
    return cachedDataPointer->UpdateTransactionAmount(id, amount);
}

bool TransactionDAO::UpdateDate(int id, QDate date)
{
    return cachedDataPointer->UpdateTransactionDate(id, date);
}

bool TransactionDAO::UpdateType(int id, TransactionType type)
{
    return cachedDataPointer->UpdateTransactionType(id, type);
}

bool TransactionDAO::UpdateComment(int id, QString comment)
{
    return cachedDataPointer->UpdateTransactionComment(id, comment);
}

bool TransactionDAO::UpdateCategory(int id, int categoryId)
{
    return cachedDataPointer->UpdateTransactionCategory(id, categoryId);
}
