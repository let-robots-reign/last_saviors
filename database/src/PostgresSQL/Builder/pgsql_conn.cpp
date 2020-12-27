#include <iostream>
#include "pgsql_conn.h"


PDBConn::PDBConn(std::shared_ptr<ConnPool> &connP) {
    this->conn_pool = connP;
}

bool PDBConn::DBConnect(DBServerInfo info) {

    return false;
}

bool PDBConn::DBExec(std::string query) {
    PQclear(res);

    auto conn = conn_pool->connection();
    this->res = PQexec(conn->connection().get(), query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cout << "Select failed: " << PQresultErrorMessage(res) << std::endl;
        return false;
    }

    return true;
}

bool PDBConn::DBExecStatus() {
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cout << "Select failed: " << PQresultErrorMessage(res) << std::endl;
        return false;
    }
    return true;
}

int PDBConn::getDBTuples() {
    if (DBExecStatus()) {
        return PQntuples(res);
    }

    return -1;
}

int PDBConn::getDBNFields() {
    if (DBExecStatus()) {
        return PQnfields(res);
    }

    return -1;
}

std::string PDBConn::DBGetValue(int i, int j) {
    if (DBExecStatus()) {
        return PQgetvalue(this->res, i, j);
    }

    return nullptr;
}

void PDBConn::DBClear() {
    PQclear(res);
}

PDBConn::~PDBConn() {
    PQclear(res);
}
