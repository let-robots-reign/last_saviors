#ifndef DATABASE_IDBCONN_H
#define DATABASE_IDBCONN_H

#include <string>
#include "db_server_info.h"

class IDBConn {
public:
//    virtual bool DBInit() = 0;

    virtual bool DBConnect(DBServerInfo info) = 0;

    virtual bool DBExec(std::string query) = 0;

    virtual bool DBExecStatus() = 0;

    virtual int getDBTuples() = 0;

    virtual int getDBNFields() = 0;

    virtual std::string DBGetValue(int i, int j) = 0;

    virtual void DBClear() = 0;
};


#endif //DATABASE_IDBCONN_H
