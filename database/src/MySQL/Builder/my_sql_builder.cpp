#include "my_sql_builder.h"

std::unique_ptr<GameDB> MySQLBuilder::buildGameDB() {
    return std::unique_ptr<GameDB>();
}

std::unique_ptr<IDBConn> MySQLBuilder::buildDataBase(DBServerInfo info) {
    return std::unique_ptr<IDBConn>();
}

std::unique_ptr<DBMS> MySQLBuilder::buildDBMS() {
    return std::unique_ptr<DBMS>();
}

std::unique_ptr<GameDB> MySQLBuilder::getProduct() {
    return std::unique_ptr<GameDB>();
}

void MySQLBuilder::reset() {

}
