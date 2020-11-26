#ifndef DATABASE_PQUESTMAPPER_H
#define DATABASE_PQUESTMAPPER_H

#include "ipquest_mapper.h"

class PQuestMapper : public IPQuestMapper {
public:
    ProgPuzzle getRandProgPuzzle() override;
};


#endif //DATABASE_PQUESTMAPPER_H
