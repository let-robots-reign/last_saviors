#include <iostream>
#include "user_mapper.h"


UsersMapper::UsersMapper(std::shared_ptr<IDBConn> &new_dbConn) {
    this->dbConn = new_dbConn;
}

bool UsersMapper::sign_in(User user) {
    dbConn->DBExec("select * from game_user where login=\'" + user.login + "\' AND password=\'" + user.password + "\';");
    if (dbConn->getDBTuples() == 0) {
        return false;
    }

    return true;
}

bool UsersMapper::sign_up(User user) {
    try {
        dbConn->DBExec("insert into game_user (login, password, name, age) values(\'" + user.login + "\', \'" + user.password + "\', \'" + user.name + "\'," + user.age + ");");
        dbConn->DBExecStatus();
    }
    catch (...) {
        return false;
    }

    return true;
}
