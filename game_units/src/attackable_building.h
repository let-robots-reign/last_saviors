#ifndef LAST_SAVIORS_ATTACKABLEBUILDING_H
#define LAST_SAVIORS_ATTACKABLEBUILDING_H

#include "unit.h"

class AttackableBuilding : public Unit {
   private:
    int health;

   public:
    void reduceHealth();
};

#endif  // LAST_SAVIORS_ATTACKABLEBUILDING_H
