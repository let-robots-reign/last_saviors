#include "gtest/gtest.h"
#include "unit.h"

TEST(TestUnit, distance) {
    Unit first(Coordinate(-2, 2));
    Unit second(Coordinate(1, 1));
    ASSERT_DOUBLE_EQ(first.distance(second), std::sqrt(10));
}

TEST(TestUnit, setCoordinate) {
    Unit unit((Coordinate()));
    Coordinate new_cords = Coordinate(1, 1);
    unit.setCoordinate(new_cords);
    EXPECT_EQ(unit.getCoordinate().getX(), new_cords.getX());
    EXPECT_EQ(unit.getCoordinate().getY(), new_cords.getY());
}