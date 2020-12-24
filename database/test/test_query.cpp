#include "gtest/gtest.h"
#include <idb_conn.h>
#include <iusers_mapper.h>
#include <iscore_mapper.h>
#include <iqquest_mapper.h>
#include <ipquest_mapper.h>
#include <DBBuilder.h>


TEST(TestGameDB, testSignIn) {
    auto builder = std::make_shared<DBBuilder>();
    std::shared_ptr<IDB> qwerty = builder->buildAllDB();

    auto qst = qwerty->getQQuestM()->getRandQuizPuzzle();
    std::cout << qst.question << std::endl;

//    User new_user;
//    new_user.login = "1337QWERTY228";
//    new_user.password = "ZXC";
//    new_user.name = "KEK";
//    new_user.age = "12";
//
//    if (user->sign_in(new_user))
//        std::cout << "HERE";
//    else
//        std::cout << "NETU";
//
//    user->sign_up(new_user);

//    auto qstM = qwerty->getQQuestM();
//
//    auto qst = qstM->getRandQuizPuzzle();
//
//    std::cout << qst.question << std::endl;
//    connector->DBExec("select * from sn_user where user_id > 4 AND user_id < 9;");
//    std::cout << "Get " << connector->getDBTuples() << "tuples, each tuple has "
//                  << connector->getDBNFields() << "fields" << std::endl;
//        // print column name
////        for (int i = 0; i < PQnfields(res); i++) {
////            std::cout << PQfname(res, i) << "              ";
////        }
//        std::cout << std::endl;
//        // print column values
//        for (int i = 0; i < connector->getDBTuples(); i++) {
//            for (int j = 0; j < connector->getDBNFields(); j++) {
//                std::cout << connector->DBGetValue(i, j) << "   ";
//            }
//            std::cout << std::endl;
//        }

//    const char conninfo[] =
//            "postgresql://postgres@localhost?port=5432&dbname=postgres&password=new_password";
//    PGconn *conn = PQconnectdb(conninfo);
//    /* Check to see that the backend connection was successfully made */
//    if (PQstatus(conn) != CONNECTION_OK) {
//        std::cout << "Connection to database failed: " << PQerrorMessage(conn)
//                  << std::endl;
//        PQfinish(conn);
//    } else {
//        std::cout << "Connection to database succeed." << std::endl;
//    }

//    PGresult *res = NULL;
//
//    std::shared_ptr<ConnPool> qwe = std::make_shared<PGConnPool>();
//
//    auto conn = qwe->connection();
//    /* SELECT demo */
//    res = PQexec(conn->connection().get(), "select * from sn_user where user_id > 4 AND user_id < 9;");
//    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
//        std::cout << "Select failed: " << PQresultErrorMessage(res) << std::endl;
//    } else {
//        std::cout << "Get " << PQntuples(res) << "tuples, each tuple has "
//                  << PQnfields(res) << "fields" << std::endl;
//        // print column name
//        for (int i = 0; i < PQnfields(res); i++) {
//            std::cout << PQfname(res, i) << "              ";
//        }
//        std::cout << std::endl;
//        // print column values
//        for (int i = 0; i < PQntuples(res); i++) {
//            for (int j = 0; j < PQnfields(res); j++) {
//                std::cout << PQgetvalue(res, i, j) << "   ";
//            }
//            std::cout << std::endl;
//        }
//    }
//    PQclear(res);



//    std::shared_ptr<ConnPool> qwe = std::make_shared<PGConnPool>();
//
//    auto conn = qwe->connection()->connection().get();
//    PQsendQuery(conn, "SELECT * FROM sn_user WHERE user_id = 4");
//    auto res = PQgetResult(conn);
//    auto ID = PQgetvalue (res ,1, 0);
//    std::cout<< "Get= " << ID <<std::endl;
//    std::cout << "Get " << PQntuples(res) << "tuples, each tuple has "
//              << PQnfields(res) << "fields" << std::endl;
//    // print column name
//    for (int i = 0; i < PQnfields(res); i++) {
//        std::cout << PQfname(res, i) << "              ";
//    }
//    std::cout << std::endl;
//    // print column values
//    for (int i = 0; i < PQntuples(res); i++) {
//        for (int j = 0; j < PQnfields(res); j++) {
//            std::cout << PQgetvalue(res, i, j) << "   ";
//        }
//        std::cout << std::endl;
//    }

//    auto ID = PQgetvalue (res ,0, 0);
//    std::cout << "KEK = " << ID << std::endl;

}











//TEST(TestGameDB, testSignUp) {
//    BDDirector *director = new BDDirector();
//    IDBBuilder *builder = new MySQLBuilder();
//    GameDB *db = director->buildDataBase(new DBServerInfo("127.0.0.1", "3000", "login", "password"));
//
//    User user;
//    user.age = 16;
//    user.id = 2;
//    user.login = "login";
//    user.password = "password";
//    user.name = "Sasha";
//
//    ASSERT_TRUE(db->sign_up(user));
//}
//
//TEST(TestGameDB, testGetUserScore) {
//    BDDirector *director = new BDDirector();
//    IDBBuilder *builder = new MySQLBuilder();
//    GameDB *db = director->buildDataBase(new DBServerInfo("127.0.0.1", "3000", "login", "password"));
//
//    User user;
//    user.age = 16;
//    user.id = 2;
//    user.login = "login";
//    user.password = "password";
//    user.name = "Sasha";
//
//    db->sign_up(user);
//
//    ASSERT_EQ(db->getUserScore(2), 100);
//
//}
