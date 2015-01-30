#ifndef CACHEDDTOLIST_H
#define CACHEDDTOLIST_H

#include <Data/DTO/TransactionDTO.h>
#include <Data/DTO/CategoryDTO.h>
#include <QObject>

class CachedData : public QObject
{
    Q_OBJECT
public:
    CachedData(QObject *parent = 0);
    CachedData(const CachedData & other);
    ~CachedData();

    CachedData & operator =(const CachedData & other);

    void ReadFile(QString fileLocation);

    void WriteFile(QString fileLocation);

    QList<TransactionDTO>   transactionList;
    QList<CategoryDTO>      categoryList;

signals:
    void MarkDirty() const;
    void MarkClean() const;


};

#endif // CACHEDDTOLIST_H
