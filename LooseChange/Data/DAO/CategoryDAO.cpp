#include "CategoryDAO.h"

CategoryDAO::CategoryDAO()
{
}

CategoryDAO::CategoryDAO(CachedData *inCachedDataPointer)
{
    cachedDataPointer = inCachedDataPointer;
}

CategoryDAO::~CategoryDAO()
{
    //cachedDataPointer to be deleted elsewhere because it is passed in.
}

QList<CategoryDTO> CategoryDAO::GetCategories()
{
//    QList<TransactionDTO> transactionList = cachedDataPointer->GetTransactionList();
//    QList<CategoryDTO> categoryList;
//    foreach (TransactionDTO transaction, transactionList)
//    {
//        bool found = false;
//        foreach (CategoryDTO category, categoryList)
//        {
//            if(category.ToString() == transaction.category.ToString())
//            {
//                found = true;
//            }
//        }
//        if(!found)
//        {
//            categoryList.append(transaction.category);
//        }
//    }
    return cachedDataPointer->GetCategoryList();
}






