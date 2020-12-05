#include "gtest/gtest.h"
#include "unit.h"

TEST(TestUnit, distance) {
    Unit first(Coordinate(2, 2));
    Unit second(Coordinate(1, 1));
    ASSERT_DOUBLE_EQ(first.distance(second), std::sqrt(2));
}