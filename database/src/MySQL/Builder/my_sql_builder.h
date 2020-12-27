#ifndef DATABASE_MYSQLBUILDER_H
#define DATABASE_MYSQLBUILDER_H

#include <memory>
#include "idb_builder.h"

class MySQLBuilder : public IDBBuilder {
public:
    std::unique_ptr<GameDB> buildGameDB() override;

    std::unique_ptr<IDBConn> buildDataBase(DBServerInfo info) override;

    std::unique_ptr<DBMS> buildDBMS() override;

    std::unique_ptr<GameDB> getProduct() override;

    void reset();

private:
    std::unique_ptr<GameDB> db = nullptr;
    std::unique_ptr<DBMS> dbms = nullptr;
    std::unique_ptr<IDBConn> db_conn = nullptr;

};


#endif //DATABASE_MYSQLBUILDER_H
