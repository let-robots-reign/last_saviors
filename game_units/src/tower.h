#ifndef LAST_SAVIORS_TOWER_H
#define LAST_SAVIORS_TOWER_H

#include "attackable_building.h"
#include "enemy.h"
#include "time.h"

class Tower : public AttackableBuilding {
   protected:
    time_t timeOfLastAttack_;
    int level_;

   public:
    explicit Tower(int health, Coordinate position = Coordinate(), int level = 1);
    virtual void attack(Enemy* targets) = 0;
    virtual bool canAttack() = 0;
    virtual Enemy* findTargets() = 0;
    void upgrade(Player* player);
};

#endif  // LAST_SAVIORS_TOWER_H
