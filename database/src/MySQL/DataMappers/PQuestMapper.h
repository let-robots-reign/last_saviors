#ifndef DATABASE_PQUESTMAPPER_H
#define DATABASE_PQUESTMAPPER_H

#include "IPQuestMapper.h"

class PQuestMapper : public IPQuestMapper {
public:
    ProgQuestion getRandProgQuestion() override;
};


#endif //DATABASE_PQUESTMAPPER_H
