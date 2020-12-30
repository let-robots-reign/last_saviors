#include "gtest/gtest.h"
#include "BinaryStream.Game.h"
#include <string>

TEST(BinaryStream, string) {
    const std::string string0("Sample Text");
    std::string string1("");

    BinaryStream stream;
    stream.Insert(string0);
    stream.Extract(string1);

    EXPECT_EQ(stream.data().size(), 0);
    EXPECT_EQ(string0, string1);
}
