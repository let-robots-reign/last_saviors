#ifndef LAST_SAVIORS_ENEMY_H
#define LAST_SAVIORS_ENEMY_H

#include "attackable_building.h"
#include "player.h"
#include "unit.h"

class Enemy : public Unit {
   private:
    int health_;
    time_t timeOfLastAttack_;

   public:
    Enemy();
    Enemy(Coordinate position) void attack(AttackableBuilding *building) = 0;
    bool canAttack() = 0;
    void reduceHealth(AttackableBuilding *building);
    void atDeath(Player *player) = 0;
};

#endif  // LAST_SAVIORS_ENEMY_H
