#ifndef LOOSECHAGEDAO_H
#define LOOSECHAGEDAO_H

#include <QList>
#include <DTO/LooseChangeDTO.h>

class LooseChangeDAO
{
public:
    LooseChangeDAO();

    /**
     * @brief ReadFile - Parses data file.
     * @param inFileName
     * @return List of LooseChangeDTOs
     */
    QList<LooseChangeDTO> ReadFile(QString fileLocation);

    /**
     * @brief WriteFile - Writes the QList to the file.
     * @param fileName
     * @param dtoList
     * @return
     */
    bool WriteFile(QString fileName, QList<LooseChangeDTO> dtoList);


};

#endif // LOOSECHAGEDAO_H
