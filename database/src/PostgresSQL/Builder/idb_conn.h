#ifndef DATABASE_IDBCONN_H
#define DATABASE_IDBCONN_H

#include <string>
#include "db_server_info.h"

class IDBConn {
public:
    virtual bool DBInit() = 0;

    virtual bool DBConnect(DBServerInfo info) = 0;

    virtual bool DBQuery(std::string query) = 0;

    virtual std::string DBStoreRes() = 0;

    virtual std::string DBFetchField(int attr) = 0;

    virtual void DBClose() = 0;
};


#endif //DATABASE_IDBCONN_H
