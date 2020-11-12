#ifndef LAST_SAVIORS_UNIT_H
#define LAST_SAVIORS_UNIT_H

class Unit {
   private:
    Coordinate position_;

   public:
    Unit();
    Unit(Coordinate position);
    double distance(const Unit &anotherUnit);
    Coordinate getCoordinate();
};

#endif  // LAST_SAVIORS_UNIT_H
