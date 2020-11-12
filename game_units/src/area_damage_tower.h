#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_H

#include "model_factory.h"
#include "tower.h"

class AreaDamageTower : public Tower {
   public:
    AreaDamageTower();
    AreaDamageTower(Coordinate position, int level = 1);
    void attack(Enemy* targets) override;
    bool canAttack() override;
    Enemy* findTargets() override;
    void upgrade(Player* player) override;

   private:
    AreaDamageTowerModel* model;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_H
