#ifndef DATABASE_IPQUESTMAPPER_H
#define DATABASE_IPQUESTMAPPER_H

#include "ProgQuestion.h"

class IPQuestMapper {
public:
    virtual ProgQuestion getRandProgQuestion() = 0;
};


#endif //DATABASE_IPQUESTMAPPER_H
