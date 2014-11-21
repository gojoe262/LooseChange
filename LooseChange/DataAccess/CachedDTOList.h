#ifndef CACHEDDTOLIST_H
#define CACHEDDTOLIST_H

#include <DataAccess/DTO/LooseChangeDTO.h>

class CachedDTOList
{
public:
    CachedDTOList();

    /**
     * @brief GetList - Gets the list
     * @return
     */
    QList<LooseChangeDTO> GetList();
    
    /**
     * @brief SetList - Clears and Sets the list to the passed in parameter
     * @param dtoList
     */
    void SetList(QList<LooseChangeDTO> inDtoList);
    
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
    bool UpdateAmount(int id, double amount);

    /**
     * @brief UpdateDate - Updates the date on the dto with the matching id
     * @param id
     * @param date
     */
    bool UpdateDate(int id, QDate date);

    /**
     * @brief UpdateTransactionType - Updates the transaction type on the dto with the matching id
     * @param id
     * @param type
     * @return
     */
    bool UpdateTransactionType(int id, TransactionType type);

    /**
     * @brief UpdateCategory
     * @param id
     * @param category
     * @return
     */
    bool UpdateCategory(int id, Category category);

    /**
     * @brief UpdateComment
     * @param id
     * @param comment
     * @return
     */
    bool UpdateComment(int id, QString comment);

private:
    QList<LooseChangeDTO> dtoList;
};

#endif // CACHEDDTOLIST_H
