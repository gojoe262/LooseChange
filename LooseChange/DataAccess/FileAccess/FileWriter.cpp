#include "FileWriter.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


FileWriter::FileWriter()
{
}


bool FileWriter::WriteFile(QList<TransactionDTO> dtoList, QString fileLocation)
{
    QFile file(fileLocation);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QJsonArray transactionArray;

        foreach (TransactionDTO dto, dtoList)
        {
            //Write to individual Transaction
            QJsonObject transaction;
            transaction["ID"] = QString::number(dto.id);
            transaction["DATE"] = dto.date.toString("yyyyMMdd");
            transaction["AMOUNT"] = dto.amount;
            transaction["TRANSACTION_TYPE"] = TransactionTypeHelper::ToString(dto.transactionType);
            transaction["CATEGORY"] = dto.category.category;
            transaction["COMMENT"] = QString(dto.comment);

            transactionArray.append(transaction);
        }

        //Write Section for all transactions
        QJsonObject mainJsonObj;
        mainJsonObj["TRANSACTIONS"] = transactionArray;

        //Write to the file
        QJsonDocument doc(mainJsonObj);
        if(file.write(doc.toJson()) < 0) //file.write(doc.toJson()) returns -1 if error
        {
            QMessageBox::information(0, "Error", "Error writing JSON Document to file.\n" + file.fileName());
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        QMessageBox::information(0, "Error", "Error writing to file " + file.fileName());
        return false;
    }
}
