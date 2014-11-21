#include "FileReader.h"

#include <QFile>
#include <QTextStream>

FileReader::FileReader()
{
}

QList<LooseChangeDTO> FileReader::ReadFile(QString fileLocation)
{
    QList<LooseChangeDTO> dtoList;
    QFile file(fileLocation);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream inStream(&file);
        while (!inStream.atEnd())
        {
            QString line = inStream.readLine();
            QStringList lineData = line.split("|---|", QString::KeepEmptyParts);

            int id = lineData[0].toInt();
            QDate date = QDate::fromString(lineData[1], "yyyyMMdd");
            double amount = lineData[2].toDouble();
            TransactionType type = TransactionTypeHelper::FromString(lineData[3]);
            Category category = CategoryHelper::FromString(lineData[4]);
            QString comment = lineData[5];

            dtoList.append(LooseChangeDTO(id,date, amount, type, category, comment));
        }
    }
    return dtoList;
}
