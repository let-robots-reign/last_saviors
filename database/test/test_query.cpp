#include <pg_conn_pool.h>
#include "gtest/gtest.h"

#include "db_server_info.h"
#include "bd_director.h"




TEST(TestGameDB, testSignIn) {
    auto pgbackend = std::make_shared<PGConnPool>();





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
