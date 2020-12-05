#ifndef LAST_SAVIORS_UNIT_H
#define LAST_SAVIORS_UNIT_H

#include "cmath"
#include "coordinate.h"

class Unit {
   private:
    Coordinate position_;

   public:
    explicit Unit(Coordinate position);
    virtual ~Unit() = default;
    double distance(const Unit &anotherUnit) const;
    inline Coordinate getCoordinate() const { return position_; };
    void setCoordinate(Coordinate new_position);
};

#endif  // LAST_SAVIORS_UNIT_H
