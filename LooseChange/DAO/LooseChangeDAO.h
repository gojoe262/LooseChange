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

    bool WriteFile(QString fileName, QList<LooseChangeDTO> dtoList);
};

#endif // LOOSECHAGEDAO_H
