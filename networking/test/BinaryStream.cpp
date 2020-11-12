#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "BinaryStream.h"

using namespace testing;

TEST(BinaryStream, int_rw) {
    BinaryStream buffer;
    int a = 1337;
    int b = 0;
    buffer.Write(a);
    buffer.Read(b);
    EXPECT_EQ(a, 1337);
    EXPECT_EQ(a, b);
    EXPECT_EQ(buffer.data().size(), 0);
}

TEST(BinaryStream, vecbyte_rw) {
    BinaryStream buffer;
    std::vector<std::byte> a {std::byte{0x1}, std::byte{0x3}, std::byte{0x3}, std::byte{0x7}};
    std::vector<std::byte> b;
    buffer.Write(a);
    buffer.Read(b);
    ASSERT_THAT(a, ElementsAre(std::byte{0x1}, std::byte{0x3}, std::byte{0x3}, std::byte{0x7}));
    ASSERT_THAT(b, ElementsAre(std::byte{0x1}, std::byte{0x3}, std::byte{0x3}, std::byte{0x7}));
    EXPECT_EQ(buffer.data().size(), 0);
}

TEST(BinaryStream, vecbyte_pushpop) {
    BinaryStream buffer;
    std::vector<std::byte> a {std::byte{0x1}, std::byte{0x3}, std::byte{0x3}, std::byte{0x7}};
    std::vector<std::byte> b;
    buffer.Push(a);
    b = buffer.Pop(a.size());
    ASSERT_THAT(a, ElementsAre(std::byte{0x1}, std::byte{0x3}, std::byte{0x3}, std::byte{0x7}));
    ASSERT_THAT(b, ElementsAre(std::byte{0x1}, std::byte{0x3}, std::byte{0x3}, std::byte{0x7}));
    EXPECT_EQ(buffer.data().size(), 0);
}

/*
TEST(BinaryStream, int_operators) {
    BinaryStream buffer;
    int a = 1337;
    int b = 0;
    buffer << a;
    b << buffer;
    EXPECT_EQ(a, 1337);
    EXPECT_EQ(a, b);
    EXPECT_EQ(buffer.data().size(), 0);
}
*/
