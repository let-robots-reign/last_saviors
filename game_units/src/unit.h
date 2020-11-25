#ifndef LAST_SAVIORS_UNIT_H
#define LAST_SAVIORS_UNIT_H

#include "coordinate.h"

class Unit {
   private:
    Coordinate position_;

   public:
    explicit Unit(Coordinate position = Coordinate());
    double distance(const Unit &anotherUnit);
    inline Coordinate getCoordinate() const { return position_; };
};

#endif  // LAST_SAVIORS_UNIT_H
