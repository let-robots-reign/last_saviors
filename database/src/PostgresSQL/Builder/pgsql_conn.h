#ifndef DATABASE_PDBCONN_H
#define DATABASE_PDBCONN_H


#include "ConnPool.h"
#include "idb_conn.h"


class PDBConn : public IDBConn {
public:
    explicit PDBConn(std::shared_ptr<ConnPool> &connP);
    ~PDBConn();

    bool DBConnect(DBServerInfo info) override;

    bool DBExec(std::string query) override;

    bool DBExecStatus() override;

    int getDBTuples() override;

    int getDBNFields() override;

    std::string DBGetValue(int i, int j) override;

    void DBClear() override;

private:
    std::shared_ptr<ConnPool> conn_pool = nullptr;
    PGresult *res = nullptr;
};


#endif //DATABASE_PDBCONN_H
