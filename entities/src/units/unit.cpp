#include "unit.h"

Unit::Unit(Coordinate position) : position_(position) {}
double Unit::distance(const Unit &anotherUnit) const {
    return std::hypot(position_.getX() - anotherUnit.position_.getX(),
                      position_.getY() - anotherUnit.position_.getY());
}
void Unit::setCoordinate(Coordinate new_position) { position_ = new_position; }
