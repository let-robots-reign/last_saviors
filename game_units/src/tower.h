#ifndef LAST_SAVIORS_TOWER_H
#define LAST_SAVIORS_TOWER_H

#include "attackable_building.h"
#include "enemy.h"

class Tower : public AttackableBuilding {
   private:
    time_t timeOfLastAttack;
    int level;

   public:
    virtual void attack(Enemy* targets) = 0;
    virtual bool canAttack() = 0;
    virtual Enemy* findTargets() = 0;
    virtual void upgrade(Player* player) = 0;
};

#endif  // LAST_SAVIORS_TOWER_H
