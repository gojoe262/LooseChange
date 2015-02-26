#ifndef FILEACCESSOR_H
#define FILEACCESSOR_H
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <Data/Cache/CachedData.h>

class FileAccessor
{
public:
    FileAccessor();
    ~FileAccessor();

    /**
     * @brief SaveFile - Saves a file using the data in the inCachedDataPointer
     * @param inCachedDataPointer
     * @return True if successfuly save, otherwise false.
     */
    bool SaveFile(CachedData *inCachedDataPointer);

    /**
     * @brief OpenFile - Opens a file and loads it to the passed in cachedData
     * @param inCachedDataPointer
     * @return - True if successful, otherwise false
     */
    bool OpenFile(CachedData *inCachedDataPointer);

    /**
     * @brief GetFileName - Gets the file name (with full location)
     * @return
     */
    QString GetFileName();

private:
    /**
     * @brief WriteFile - Writes the QList of dtos to the file.
     * @param dtoList
     * @param fileLocation
     * @return True if successfully written, otherwise false.
     */
    bool WriteFile(QList<TransactionDTO> *transactionList, QList<CategoryDTO> *categoryList, QString fileLocation);

    /**
     * @brief ReadFile - Reads a file and stores the data in the transactionList and categoryList
     * @param transactionList
     * @param categoryList
     * @param fileLocation
     */
    void ReadFile(QList<TransactionDTO> *transactionList, QList<CategoryDTO> *categoryList, QString fileLocation);

    /**
     * @brief currentFileLocation - Variable to hold the current file location.
     */
    QString currentFileLocation;
};

#endif // FILEACCESSOR_H
