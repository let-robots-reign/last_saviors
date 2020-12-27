#include "gtest/gtest.h"
#include "bd_director.h"
#include "my_sql_builder.h"

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
