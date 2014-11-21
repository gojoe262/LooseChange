#include "FileWriter.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

FileWriter::FileWriter()
{
}


bool FileWriter::WriteFile(QList<LooseChangeDTO> dtoList, QString fileLocation)
{
    QFile file(fileLocation);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream outStream(&file);
        foreach (LooseChangeDTO dto, dtoList)
        {
            outStream << dto.id << "|---|"
                      << dto.date.toString("yyyyMMdd") << "|---|"
                      << dto.amount << "|---|"
                      << TransactionTypeHelper::ToString(dto.transactionType) << "|---|"
                      << CategoryHelper::ToString(dto.category)<< "|---|"
                      << dto.comment << "\n";
        }
        return true;
    }
    else
    {
        QMessageBox::information(0, "Error", "Error writing to file " + file.fileName());
        return false;
    }
}
