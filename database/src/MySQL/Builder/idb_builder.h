#ifndef DATABASE_IDBBUILDER_H
#define DATABASE_IDBBUILDER_H

#include "game_db.h"
#include "idb_conn.h"
#include "db_server_info.h"
#include "dbms.h"

class IDBBuilder {
public:
    virtual std::unique_ptr<GameDB> buildGameDB() = 0;

    virtual std::unique_ptr<IDBConn> buildDataBase(DBServerInfo info) = 0;

    virtual std::unique_ptr<DBMS> buildDBMS() = 0;

    virtual std::unique_ptr<GameDB> getProduct() = 0;
};


#endif //DATABASE_IDBBUILDER_H
