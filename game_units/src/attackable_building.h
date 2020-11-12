#ifndef LAST_SAVIORS_ATTACKABLEBUILDING_H
#define LAST_SAVIORS_ATTACKABLEBUILDING_H

#include "unit.h"

class AttackableBuilding : public Unit {
   private:
    int health_;

   public:
    explicit AttackableBuilding(int health, Coordinate position = Coordinate());
    void reduceHealth(int value);
    void setHeath(int value);
};

#endif  // LAST_SAVIORS_ATTACKABLEBUILDING_H
