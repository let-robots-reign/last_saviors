#include "gtest/gtest.h"

#include "../MySQL/Builder/BDDirector.h"
#include "../MySQL/Builder/MySQLBuilder.h"

TEST(TestGameDB, testSignIn) {
    BDDirector *director = new BDDirector();
    IDBBuilder *builder = new MySQLBuilder();
    GameDB *db = director->buildDataBase(new DBServerInfo("127.0.0.1", "3000", "login", "password"));

    User user;
    user.age = 15;
    user.id = 1;
    user.login = "login";
    user.password = "password";
    user.name = "Ilya";

    ASSERT_TRUE(db->sign_in(user));

}

TEST(TestGameDB, testSignUp) {
    BDDirector *director = new BDDirector();
    IDBBuilder *builder = new MySQLBuilder();
    GameDB *db = director->buildDataBase(new DBServerInfo("127.0.0.1", "3000", "login", "password"));

    User user;
    user.age = 16;
    user.id = 2;
    user.login = "login";
    user.password = "password";
    user.name = "Sasha";

    ASSERT_TRUE(db->sign_up(user));
}

TEST(TestGameDB, testGetUserScore) {
    BDDirector *director = new BDDirector();
    IDBBuilder *builder = new MySQLBuilder();
    GameDB *db = director->buildDataBase(new DBServerInfo("127.0.0.1", "3000", "login", "password"));

    User user;
    user.age = 16;
    user.id = 2;
    user.login = "login";
    user.password = "password";
    user.name = "Sasha";

    db->sign_up(user);

    ASSERT_EQ(db->getUserScore(2), 100);

}
