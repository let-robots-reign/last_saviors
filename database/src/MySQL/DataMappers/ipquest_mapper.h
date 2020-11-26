#ifndef DATABASE_IPQUESTMAPPER_H
#define DATABASE_IPQUESTMAPPER_H

#include "prog_question.h"

class IPQuestMapper {
public:
    virtual ProgQuestion getRandProgQuestion() = 0;
};


#endif //DATABASE_IPQUESTMAPPER_H
