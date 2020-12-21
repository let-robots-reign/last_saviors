#include "unit.h"

Unit::Unit(Coordinate position) : position_(position) {}
double Unit::distance(const Unit &anotherUnit) const {
    return Coordinate::distance(position_, anotherUnit.position_);
}
void Unit::setCoordinate(Coordinate new_position) { position_ = new_position; }
