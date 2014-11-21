#ifndef FILEREADER_H
#define FILEREADER_H

#include <DataAccess/DTO/LooseChangeDTO.h>

class FileReader
{
public:
    FileReader();
    
    QList<LooseChangeDTO> ReadFile(QString fileLocation);
};

#endif // FILEREADER_H
