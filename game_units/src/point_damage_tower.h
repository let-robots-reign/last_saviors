#ifndef LAST_SAVIORS_POINT_DAMAGE_TOWER_H
#define LAST_SAVIORS_POINT_DAMAGE_TOWER_H

#include "point_damage_tower_model.h"
#include "tower.h"
class PointDamageTower : public Tower {
   public:
    void attack(Enemy* targets) override;
    bool canAttack() override;
    Enemy* findTargets() override;
    void upgrade(Player* player) override;

   private:
    PointDamageTowerModel* model;
};

#endif  // LAST_SAVIORS_POINT_DAMAGE_TOWER_H
