#ifndef LOOSECHAGEDAO_H
#define LOOSECHAGEDAO_H

#include <QList>
#include <LooseChangeDTO.h>

class LooseChangeDAO
{
public:
    LooseChangeDAO();

    /**
     * @brief dtoList
     */
    QList<LooseChangeDTO> dtoList;


    /**
     * @brief ReadFile - Parses data file.
     * @param inFileName
     * @return List of LooseChangeDTOs
     */
    QList<LooseChangeDTO> ReadFile(QString inFileName);

    /**
     * @brief FetchFileLocation - Opens dialog to open a file.
     * @return Locatiom of the chosen file
     */
    QString FetchFileLocation(QWidget* parent);

};

#endif // LOOSECHAGEDAO_H
