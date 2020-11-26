#ifndef DATABASE_IPQUESTMAPPER_H
#define DATABASE_IPQUESTMAPPER_H

#include "prog_puzzle.h"

class IPQuestMapper {
public:
    virtual ProgPuzzle getRandProgPuzzle() = 0;
};


#endif //DATABASE_IPQUESTMAPPER_H
