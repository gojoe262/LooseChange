#include "FileAccessor.h"
#include <QFileDialog>
#include <QMessageBox>

FileAccessor::FileAccessor()
{

}

FileAccessor::~FileAccessor()
{

}

QString FileAccessor::GetFileName()
{
    return currentFileLocation;
}

bool FileAccessor::SaveFile(CachedData *inCachedDataPointer)
{
    QString fileLocation = QFileDialog::getSaveFileName(NULL, QObject::tr("Save File"),
                                                        currentFileLocation,
                                                        QObject::tr("LooseChange Files (*.json);;All Files (*.* *"));
    if(!WriteFile(&(inCachedDataPointer->transactionList), &(inCachedDataPointer->categoryList), fileLocation))
    {
        return false;
    }
    currentFileLocation = fileLocation;
    return true;
}

bool FileAccessor::OpenFile(CachedData *inCachedDataPointer)
{
    QString fileLocation = QFileDialog::getOpenFileName(NULL, QObject::tr("Open File"), currentFileLocation,
                                                        QObject::tr("LooseChange Files (*.json);;All Files (*.* *"));
    if(fileLocation != "")
    {
        /// Should check if the file was read in correctly. Maybe an exception will be caught???
        ReadFile(&(inCachedDataPointer->transactionList), &(inCachedDataPointer->categoryList), fileLocation);
        currentFileLocation = fileLocation;
        return true;
    }
    return false;
}

bool FileAccessor::WriteFile(QList<TransactionDTO> *transactionList, QList<CategoryDTO> *categoryList, QString fileLocation)
{
    QFile file(fileLocation);
    bool successful = false;
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        //Add Transactions
        QJsonArray transactionJSONArray;
        foreach (TransactionDTO transaction, *transactionList)
        {
            //Write to individual Transaction
            QJsonObject transactionJSON;
            transactionJSON["ID"] = QString(transaction.id);
            transactionJSON["DATE"] = transaction.date.toString("yyyyMMdd");
            transactionJSON["AMOUNT"] = transaction.amount;
            transactionJSON["TRANSACTION_TYPE"] = TransactionTypeHelper::ToString(transaction.transactionType);
            transactionJSON["CATEGORY_ID"] = QString(transaction.categoryId);
            transactionJSON["COMMENT"] = QString(transaction.comment);

            transactionJSONArray.append(transactionJSON);
        }

        //Add Categories
        QJsonArray categoryJSONArray;
        foreach(CategoryDTO category, *categoryList)
        {
            QJsonObject categoryJSON;
            categoryJSON["ID"] = QString(category.id);
            categoryJSON["DESCRIPTION"] = QString(category.description);

            categoryJSONArray.append(categoryJSON);
        }

        //Write Section for all transactions
        QJsonObject mainJsonObj;
        mainJsonObj["TRANSACTIONS"] = transactionJSONArray;
        mainJsonObj["CATEGORIES"] = categoryJSONArray;

        //Write to the file
        QJsonDocument doc(mainJsonObj);
        if(file.write(doc.toJson()) >= 0) //file.write(doc.toJson()) returns -1 if error
        {
            successful = true;
        }
    }
    return successful;
}

void FileAccessor::ReadFile(QList<TransactionDTO> *transactionList, QList<CategoryDTO> *categoryList, QString fileLocation)
{
    QFile file(fileLocation);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // Get Raw Data from file
        QByteArray rawData = file.readAll();

        // Parse document
        QJsonDocument doc(QJsonDocument::fromJson(rawData));

        // Get the Json Object
        QJsonObject mainJsonObj = doc.object();

        // Access category properties
        QJsonArray categoryArray = mainJsonObj["CATEGORIES"].toArray();
        int categorySize = categoryArray.size();
        for (int i = 0; i < categorySize; i++)
        {
            QJsonObject category = categoryArray.at(i).toObject();
            QString id = category["ID"].toString();
            QString description = category["DESCRIPTION"].toString();
            categoryList->append(CategoryDTO(id, description));
        }

        // Access transaction properties
        QJsonArray transacitonsArray = mainJsonObj["TRANSACTIONS"].toArray();
        int transactionSize = transacitonsArray.size();
        for (int i = 0; i < transactionSize; i++)
        {
            QJsonObject transaction = transacitonsArray.at(i).toObject();
            QString id = transaction["ID"].toString();
            QDate date = QDate::fromString(transaction["DATE"].toString(), "yyyyMMdd");
            double amount = transaction["AMOUNT"].toDouble();
            TransactionType type = TransactionTypeHelper::FromString(transaction["TRANSACTION_TYPE"].toString());
            QString categoryId = transaction["CATEGORY_ID"].toString();
            QString comment = transaction["COMMENT"].toString();

            transactionList->append(TransactionDTO(id, date, amount, type, categoryId, comment));
        }
    }
    file.close();
}
