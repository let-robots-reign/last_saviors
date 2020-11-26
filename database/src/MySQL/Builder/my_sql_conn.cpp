#include "my_sql_conn.h"

bool MySQLConn::DBInit() {
    return false;
}

bool MySQLConn::DBConnect(DBServerInfo info) {
    return false;
}

bool MySQLConn::DBQuery(std::string query) {
    return false;
}

std::string MySQLConn::DBStoreRes() {
    return nullptr;
}

std::string MySQLConn::DBFetchField(int attr) {
    return nullptr;
}

void MySQLConn::DBClose() {

}
