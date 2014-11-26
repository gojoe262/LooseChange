#ifndef CACHEDDTOLIST_H
#define CACHEDDTOLIST_H

#include <DataAccess/DTO/TransactionDTO.h>

class CachedDTOList
{
public:
    CachedDTOList();
    ~CachedDTOList();

    /**
     * @brief GetList - Gets the list
     * @return
     */
    QList<TransactionDTO> GetList();
    
    /**
     * @brief SetList - Clears and Sets the list to the passed in parameter
     * @param dtoList
     */
    void SetList(QList<TransactionDTO> inDtoList);
    
    /**
     * @brief ClearList - Removes all items from the list
     */
    void ClearList();
    
    /**
     * @brief Add - Adds the dto to the list
     * @param dto
     */
    void Add(TransactionDTO dto);

    /**
     * @brief Delete - Removes the dto with the matching id
     * @param inDto
     */
    void Delete(TransactionDTO inDto);
    
    /**
     * @brief Update - Update the dto with the matching id to inDto
     * @param inDto
     * @return
     */
    void Update(TransactionDTO inDto);

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
    QList<TransactionDTO> dtoList;
};

#endif // CACHEDDTOLIST_H
