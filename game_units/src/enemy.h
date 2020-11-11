#ifndef LAST_SAVIORS_ENEMY_H
#define LAST_SAVIORS_ENEMY_H

#include "attackable_building.h"
#include "player.h"
#include "unit.h"

class Ememy : public Unit {
   private:
    int health;
    time_t timeOfLastAttack;

   public:
    void attack(AttackableBuilding *building) = 0;
    bool canAttack() = 0;
    void reduceHealth(AttackableBuilding *building);
    void atDeath(Player *player) = 0;
};

#endif  // LAST_SAVIORS_ENEMY_H
