#ifndef DATABASE_IDBBUILDER_H
#define DATABASE_IDBBUILDER_H


#include "GameDB.h"
#include "IDBConn.h"
#include "../Data/DBServerInfo.h"
#include "DBMS.h"

class IDBBuilder {
public:
    virtual std::unique_ptr<GameDB> buildGameDB() = 0;
    virtual std::unique_ptr<IDBConn> buildDataBase(DBServerInfo info) = 0;
    virtual std::unique_ptr<DBMS> buildDBMS() = 0;
    virtual std::unique_ptr<GameDB> getProduct() = 0;
};


#endif //DATABASE_IDBBUILDER_H
