#ifndef CATEGORYDAO_H
#define CATEGORYDAO_H

#include <DataAccess/DTO/TransactionDTO.h>
#include <DataAccess/DTO/CategoryDTO.h>

class CategoryDAO
{
public:
    CategoryDAO();
    CategoryDAO(QList<TransactionDTO> inTransactionList);

    QList<CategoryDTO> GetCategories(QList<TransactionDTO> inTransactionList);
    QList<CategoryDTO> GetCategories();

private:
    QList<TransactionDTO> transactionList;
};

#endif // CATEGORYDAO_H
