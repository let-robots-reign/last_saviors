#ifndef LAST_SAVIORS_ATTACKABLEBUILDING_H
#define LAST_SAVIORS_ATTACKABLEBUILDING_H

#include "unit.h"

class AttackableBuilding : public Unit {
   private:
    int health;

   public:
    AttackableBuilding();
    AttackableBuilding(Coordinate position);
    void reduceHealth();
};

#endif  // LAST_SAVIORS_ATTACKABLEBUILDING_H
