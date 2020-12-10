#include <iostream>
#include "user_mapper.h"

bool UsersMapper::sign_in(User user) {
    std::string query = "SELECT * FROM game_user WHERE login ='" + user.login + "AND" + "password =" + user.password + ";";

    auto conn = dbConn->connection();
    auto res_deleter = [](PGresult* r) { PQclear(r);};
    std::unique_ptr<PGresult, decltype(res_deleter)> result(PQexec(reinterpret_cast<PGconn *>(conn.get()), query.c_str()), res_deleter);

    if (PQresultStatus(result.get()) != PGRES_TUPLES_OK) {
        return false;
    }

    if (PQntuples(result.get()) == 0) {
        return false;
    }

    return true;
}

bool UsersMapper::sign_up(User user) {
    std::string query = "INSERT INTO game_user (login, password, name, age) values "
                   "('" + user.login +
                   "', '" + user.password +
                   "', '" + user.name +
                   "', '" + std::string(user.age) + "');";

    auto conn = dbConn->connection();
    auto res_deleter = [](PGresult* r) { PQclear(r);};
    std::unique_ptr<PGresult, decltype(res_deleter)> result(PQexec(reinterpret_cast<PGconn *>(conn.get()), query.c_str()), res_deleter);

    if (PQresultStatus(result.get()) != PGRES_COMMAND_OK) {
        std::cout << "Insert into table failed: " << PQresultErrorMessage(result.get())
                  << std::endl;
        return false;
    }

    return true;
}

UsersMapper::UsersMapper(std::shared_ptr<PGConnPool> new_dbConn) {
    this->dbConn = new_dbConn;
}
