#include "FileReader.h"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


FileReader::FileReader()
{
}

void FileReader::ReadFile(QString fileLocation,
                          QList<TransactionDTO> &transactionList,
                          QList<CategoryDTO> &categoryList)
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
            int id = category["ID"].toString().toInt();
            QString description = category["DESCRIPTION"].toString();
            categoryList.append(CategoryDTO(id, description));
        }

        // Access transaction properties
        QJsonArray transacitonsArray = mainJsonObj["TRANSACTIONS"].toArray();
        int transactionSize = transacitonsArray.size();
        for (int i = 0; i < transactionSize; i++)
        {
            QJsonObject transaction = transacitonsArray.at(i).toObject();
            int id = transaction["ID"].toString().toInt();
            QDate date = QDate::fromString(transaction["DATE"].toString(), "yyyyMMdd");
            double amount = transaction["AMOUNT"].toDouble();
            TransactionType type = TransactionTypeHelper::FromString(transaction["TRANSACTION_TYPE"].toString());
            int categoryId = transaction["CATEGORY_ID"].toString().toInt();
            QString comment = transaction["COMMENT"].toString();

            transactionList.append(TransactionDTO(id, date, amount, type, categoryId, comment));
        }
    }
}
