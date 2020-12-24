#ifndef DATABASE_IPQUESTMAPPER_H
#define DATABASE_IPQUESTMAPPER_H


#include "idb_conn.h"
#include "prog_puzzle.h"


class IPQuestMapper {
public:
    virtual ProgPuzzle getRandProgPuzzle() = 0;

protected:
    std::shared_ptr<IDBConn> dbConn = nullptr;
};


#endif //DATABASE_IPQUESTMAPPER_H
