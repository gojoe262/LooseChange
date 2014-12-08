#ifndef FILEREADER_H
#define FILEREADER_H

#include <Data/DTO/TransactionDTO.h>

class FileReader
{
public:
    FileReader();
    
    /**
     * @brief ReadFile - Reads in a JSON file and returns a QList of transactionDTOs.
     * @param fileLocation
     * @return
     */
    QList<TransactionDTO> ReadFile(QString fileLocation);
};

#endif // FILEREADER_H
