#ifndef CACHEDDTOLIST_H
#define CACHEDDTOLIST_H

#include <DTO/LooseChangeDTO.h>

class CachedDTOList
{
public:
    CachedDTOList();

    /**
     * @brief ClearList - Removes all items from the list
     */
    void ClearList();

    /**
     * @brief Add - Adds the dto to the list
     * @param dto
     */
    void Add(LooseChangeDTO dto);

    /**
     * @brief Delete - Removes the dto with the matching id
     * @param inDto
     */
    void Delete(LooseChangeDTO inDto);

    /**
     * @brief GetList - Gets the list
     * @return
     */
    QList<LooseChangeDTO> GetList();

    /**
     * @brief Update - Update the dto with the matching id to inDto
     * @param inDto
     * @return
     */
    void Update(LooseChangeDTO inDto);

    /**
     * @brief UpdateAmount - Updates the amount on the dto with the matching id
     * @param id
     * @param amount
     */
    void UpdateAmount(int id, double amount);

    /**
     * @brief UpdateDate - Updates the date on the dto with the matching id
     * @param id
     * @param date
     */
    void UpdateDate(int id, QDate date);



private:
    QList<LooseChangeDTO> dtoList;
};

#endif // CACHEDDTOLIST_H
