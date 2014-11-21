#ifndef LOOSECHAGEDAO_H
#define LOOSECHAGEDAO_H

#include <QList>
#include <DataAccess/DTO/LooseChangeDTO.h>
#include <DataAccess/CachedDTOList.h>


class LooseChangeDAO : public QObject
{
    Q_OBJECT
public:
    LooseChangeDAO(QWidget *parent = 0);

    ~LooseChangeDAO();

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
    void WriteFile(QString fileName);

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
     * @brief UpdateAmount - Updates the amount on the dto with the matching Id
     * @param id
     * @param amount
     */
    void UpdateAmount(int id, double amount);

    /**
     * @brief UpdateDate - Updates the date on the dto with the matching Id
     * @param id
     * @param date
     */
    void UpdateDate(int id, QDate date);

    /**
     * @brief UpdateTransactionType - Updates the transaction type on the dto with the matching Id
     * @param id
     * @param type
     */
    void UpdateTransactionType(int id, TransactionType type);

    /**
     * @brief UpdateCategory - Updates the Category on the dto with the matching Id
     * @param id
     * @param category
     */
    void UpdateCategory(int id, Category category);

    /**
     * @brief UpdateComment - Updates the comment on the dto with the matching Id
     * @param id
     * @param comment
     */
    void UpdateComment(int id, QString comment);

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

signals:
    void DataChanged(bool changed);

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
     * @brief MarkClean
     */
    void MarkClean();

    /**
     * @brief isDirty - Determines if the cachedList has pending changes
     */
    bool isDirty;

};

#endif // LOOSECHAGEDAO_H
