#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "BinaryStream.h"

using namespace testing;

TEST(BinaryStream, int_insert_extract) {
    BinaryStream buffer;
    int a = 1337;
    int b = 0;
    buffer.Insert(a);
    buffer.Extract(b);
    EXPECT_EQ(a, 1337);
    EXPECT_EQ(a, b);
    EXPECT_EQ(buffer.data().size(), 0);
}


TEST(BinaryStream, different_insert_extract) {
    BinaryStream buffer;
    int a = 1337;
    char b = 'c';
    buffer.Insert(a);
    buffer.Insert(b);
    buffer.Extract(a);
    buffer.Extract(b);
    EXPECT_EQ(a, 1337);
    EXPECT_EQ(b, 'c');
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


namespace {
    // alignment
    struct sample_struct {
        int8_t i8;
        int32_t i32;
        char c3[3];
        friend constexpr bool operator== (const sample_struct & left, const sample_struct & right) {
            return
                left.i8    == right.i8 &&
                left.i32   == right.i32 &&
                left.c3[0] == right.c3[0] &&
                left.c3[1] == right.c3[1] &&
                left.c3[2] == right.c3[2]
            ;
        }
    };
}

TEST(BinaryStream, sample_struct) {
    BinaryStream buffer;
    const sample_struct first { 27, 1337, { 'a', 'b', 'c' } };
    sample_struct second {};
    buffer << first;
    buffer >> second;
    EXPECT_EQ(first, second);
}


TEST(BinaryStream, int_operators) {
    BinaryStream buffer;
    const int a = 1337;
    int b = 0;
    buffer << a;
    buffer >> b;
    EXPECT_EQ(a, 1337);
    EXPECT_EQ(a, b);
    EXPECT_EQ(buffer.data().size(), 0);
}
