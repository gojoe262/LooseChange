#ifndef CACHEDDTOLIST_H
#define CACHEDDTOLIST_H

#include <DTO/LooseChangeDTO.h>

class CachedDTOList
{
public:
    CachedDTOList();

    void ClearList();

    void Add(LooseChangeDTO dto);

    QList<LooseChangeDTO> GetList();

    void Update(LooseChangeDTO inDto);

    void Delete(LooseChangeDTO inDto);

private:
    QList<LooseChangeDTO> dtoList;
};

#endif // CACHEDDTOLIST_H
