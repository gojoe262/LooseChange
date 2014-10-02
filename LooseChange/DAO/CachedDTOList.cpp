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
