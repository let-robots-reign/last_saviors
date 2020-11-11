#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_H

#include "area_damage_tower_model.h"
#include "tower.h"
class AreaDamageTower : public Tower {
   public:
    void attack(Enemy* targets) override;
    bool canAttack() override;
    Enemy* findTargets() override;
    void upgrade(Player* player) override;

   private:
    AreaDamageTowerModel* model;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_H
