#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_H

#include "model_factory.h"
#include "tower.h"

class AreaDamageTower : public Tower {
   private:
    const AreaDamageTowerModel* model_;

   public:
    explicit AreaDamageTower(AreaDamageTowerModel* model,
                             Coordinate position = Coordinate(), int level = 1);
    void attack(Enemy* targets) override;
    bool canAttack() override;
    Enemy* findTargets() override;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_H
