#ifndef LOOSECHAGEDAO_H
#define LOOSECHAGEDAO_H

#include <QList>
#include <DTO/LooseChangeDTO.h>


class LooseChangeDAO
{
public:
    LooseChangeDAO();

    /**
     * @brief ReadFile - Parses data file. Loads the cached list
     * @param inFileName
     * @return List of LooseChangeDTOs
     */
    QList<LooseChangeDTO> ReadFile(QString fileLocation);

    /**
     * @brief WriteFile - Writes the currently cachedList to the file.
     * @param fileName
     * @param dtoList
     * @return
     */
    bool WriteFile(QString fileName);




    /**
     * @brief GetList - Gets the currently cached list
     * @return
     */
    QList<LooseChangeDTO> GetList();

    /**
     * @brief Add - Adds the dto to the cached List
     * @param inDto
     * @return
     */
    bool Add(LooseChangeDTO inDto);

    /**
     * @brief Update - Update the dto in cachedList with the matching id to inDto
     * @param inDto
     * @return
     */
    bool Update(LooseChangeDTO inDto);

    /**
     * @brief Delete - Deletes the dto in cachedList with the matching id to inDto
     * @param inDto
     * @return
     */
    bool Delete(LooseChangeDTO inDto);





    /**
     * @brief IsDirty - Determines if the cachedList has pending changes
     * that are not saved to the file.
     * @return True if dirty, otherwise false
     */
    bool IsDirty();


private:
    /**
     * @brief cachedDtoList - The cached List of Dtos.
     */
    CachedDTOList cachedList;

    /**
     * @brief MarkDirty - Marks the DAO as dirty (changes have been made that are not
     */
    void MarkDirty();

    /**
     * @brief isDirty - Determines if the cachedList has pending changes
     */
    bool isDirty;

};

#endif // LOOSECHAGEDAO_H
