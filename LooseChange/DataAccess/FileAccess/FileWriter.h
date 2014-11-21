#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>
#include <DataAccess/DTO/LooseChangeDTO.h>

class FileWriter
{
public:
    FileWriter();
    
    bool WriteFile(QList<LooseChangeDTO> dtoList, QString fileLocation);
    
};

#endif // FILEWRITER_H
