#ifndef LAST_SAVIORS_UNIT_H
#define LAST_SAVIORS_UNIT_H

class Unit {
   public:
    Coordinate position;
    double distance(const Unit &anotherUnit);
};

#endif  // LAST_SAVIORS_UNIT_H
