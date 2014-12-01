#include "CategoryDAO.h"

CategoryDAO::CategoryDAO()
{
}
\
CategoryDAO::CategoryDAO(QList<TransactionDTO> inTransactionList)
{
    transactionList = inTransactionList;
}

QList<CategoryDTO> CategoryDAO::GetCategories()
{
    return GetCategories(transactionList);
}

QList<CategoryDTO> CategoryDAO::GetCategories(QList<TransactionDTO> inTransactionList)
{
    QList<CategoryDTO> categoryList;
    foreach (TransactionDTO transaction, inTransactionList)
    {
        bool found = false;
        foreach (CategoryDTO category, categoryList)
        {
            if(category.ToString() == transaction.category.ToString())
            {
                found = true;
            }
        }
        if(!found)
        {
            categoryList.append(transaction.category);
        }
    }
    return categoryList;
}





