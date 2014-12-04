#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>
#include <Data/Objects/TransactionDTO.h>

class FileWriter
{
public:
    FileWriter();
    
    /**
     * @brief WriteFile - Writes the QList of dtos to the file.
     * @param dtoList
     * @param fileLocation
     * @return True if successfully written, otherwise false.
     */
    bool WriteFile(QList<TransactionDTO> dtoList, QString fileLocation);
    
};

#endif // FILEWRITER_H
