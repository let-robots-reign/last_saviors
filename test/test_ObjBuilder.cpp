#include "gtest/gtest.h"
#include "../MySQL//Builder/BDDirector.h"
#include "../MySQL/Builder/MySQLBuilder.h"

TEST(TestBuilder, testSettingDirector) {
    BDDirector *director = new BDDirector();
    IDBBuilder *builder = new MySQLBuilder();
    ASSERT_TRUE(director->setDirector(builder));

    delete builder;
    delete director;
}

TEST(TestLevel, testBuildDatabse) {
    BDDirector *director = new BDDirector();
    IDBBuilder *builder = new MySQLBuilder();
    ASSERT_TRUE(director->buildDataBase(new DBServerInfo("127.0.0.1", "3000", "login", "password")));

    delete builder;
    delete director;
}
