#include "CachedDTOList.h"

CachedDTOList::CachedDTOList()
{
}

void CachedDTOList::ClearList()
{
    dtoList.clear();
}

void CachedDTOList::Add(LooseChangeDTO dto)
{
    dtoList.append(dto);
}

QList<LooseChangeDTO> CachedDTOList::GetList()
{
    return dtoList;
}


void CachedDTOList::Update(LooseChangeDTO inDto)
{
    for(int i = 0; i < dtoList.count(); i++)
    {
        if(dtoList.at(i).id == inDto.id)
        {
            dtoList.replace(i, inDto);
        }
    }
}

bool CachedDTOList::UpdateAmount(int id, double amount)
{
    bool changesMade = false;
    for(int i = 0; i < dtoList.count(); i++)
    {
        if(dtoList.at(i).id == id)
        {
            if(dtoList[i].amount != amount)
            {
                dtoList[i].amount = amount;
                changesMade = true;
            }
        }
    }
    return changesMade;
}

void CachedDTOList::Delete(LooseChangeDTO inDto)
{
    for(int i = 0; i < dtoList.count(); i++)
    {
        if(dtoList.at(i).id == inDto.id)
        {
            dtoList.removeAt(i);
            i--;
        }
    }
}

bool CachedDTOList::UpdateDate(int id, QDate date)
{
    bool changesMade = false;
    for(int i = 0; i < dtoList.count(); i++)
    {
        if(dtoList.at(i).id == id)
        {
            if(dtoList[i].date != date)
            {
                dtoList[i].date = date;
                changesMade = true;
            }
        }
    }
    return changesMade;
}
