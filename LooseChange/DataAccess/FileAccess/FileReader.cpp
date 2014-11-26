#include "FileReader.h"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


FileReader::FileReader()
{
}

QList<TransactionDTO> FileReader::ReadFile(QString fileLocation)
{
    QList<TransactionDTO> dtoList;
    QFile file(fileLocation);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // Get Raw Data from file
        QByteArray rawData = file.readAll();

        // Parse document
        QJsonDocument doc(QJsonDocument::fromJson(rawData));

        // Get the Json Object
        QJsonObject json = doc.object();

        // Access properties
        QJsonArray transacitonsArray = json["TRANSACTIONS"].toArray();

        int size = transacitonsArray.size();
        for (int i = 0; i < size; i++)
        {
            QJsonObject transaction = transacitonsArray.at(i).toObject();
            int id = transaction["ID"].toString().toInt();
            QDate date = QDate::fromString(transaction["DATE"].toString(), "yyyyMMdd");
            double amount = transaction["AMOUNT"].toDouble();
            TransactionType type = TransactionTypeHelper::FromString(transaction["TRANSACTION_TYPE"].toString());
            Category category = CategoryHelper::FromString(transaction["CATEGORY"].toString());
            QString comment = transaction["COMMENT"].toString();

            dtoList.append(TransactionDTO(id, date, amount, type, category, comment));
        }
    }
    return dtoList;
}


