#ifndef LAST_SAVIORS_POINT_DAMAGE_TOWER_H
#define LAST_SAVIORS_POINT_DAMAGE_TOWER_H

#include "model_factory.h"
#include "tower.h"

class PointDamageTower : public Tower {
   public:
    PointDamageTower();
    PointDamageTower(Coordinate position, int level = 1);
    void attack(Enemy* targets) override;
    bool canAttack() override;
    Enemy* findTargets() override;
    void upgrade(Player* player) override;

   private:
    PointDamageTowerModel* model;
};

#endif  // LAST_SAVIORS_POINT_DAMAGE_TOWER_H
