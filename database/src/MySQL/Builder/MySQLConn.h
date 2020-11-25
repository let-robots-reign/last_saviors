#ifndef DATABASE_MYSQLCONN_H
#define DATABASE_MYSQLCONN_H


#include "IDBConn.h"

class MySQLConn : public IDBConn {
public:
    bool DBInit() override;

    bool DBConnect(DBServerInfo info) override;

    bool DBQuery(std::string query) override;

    std::string DBStoreRes() override;

    std::string DBFetchField(int attr) override;

    void DBClose() override;

private:
//    unique_ptr<sql::Driver> driver    ;
//    unique_ptr<sql::Connection> con;
//    shared_ptr<sql::Statement> stmt;
//    shared_ptr<sql::ResultSet> res;
};


#endif //DATABASE_MYSQLCONN_H
