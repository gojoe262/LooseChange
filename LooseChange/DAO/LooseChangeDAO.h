#ifndef LOOSECHAGEDAO_H
#define LOOSECHAGEDAO_H

#include <QList>
#include <DTO/LooseChangeDTO.h>

class LooseChangeDAO
{
public:
    LooseChangeDAO();

    /**
     * @brief OpenFile - Opens a file and returns the list
     *        of LooseChangeDTOs represented by the file
     * @return List of LooseChangeDTO's
     */
    QList<LooseChangeDTO> OpenFile(QString fileLocation);

    bool SaveFile(QString fileLocation, QList<LooseChangeDTO> dtoList);




private:
    /**
     * @brief ReadFile - Parses data file.
     * @param inFileName
     * @return List of LooseChangeDTOs
     */
    QList<LooseChangeDTO> ReadFile(QString fileLocation);

    bool WriteFile(QString fileName, QList<LooseChangeDTO> dtoList);
};

#endif // LOOSECHAGEDAO_H
