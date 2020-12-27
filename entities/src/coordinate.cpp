#include "coordinate.h"

Coordinate::Coordinate() : x(0), y(0) {}

Coordinate::Coordinate(double px, double py) : x(px), y(py) {}
double Coordinate::distance(const Coordinate& first_coordinate,
                            const Coordinate& second_coordinate) {
    return std::hypot(first_coordinate.getX() - second_coordinate.getX(),
                      first_coordinate.getY() - second_coordinate.getY());
}
