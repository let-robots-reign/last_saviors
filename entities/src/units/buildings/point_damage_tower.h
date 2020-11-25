#ifndef LAST_SAVIORS_POINT_DAMAGE_TOWER_H
#define LAST_SAVIORS_POINT_DAMAGE_TOWER_H

#include "model_factory.h"
#include "tower.h"

class PointDamageTower : public Tower {
   private:
    const PointDamageTowerModel* model_;

   public:
    explicit PointDamageTower(const PointDamageTowerModel* model,
                              Coordinate position = Coordinate(),
                              int level = 1);
    void attack(Enemy* targets) override;
    bool canAttack() override;
    Enemy* findTargets() override;
};

#endif  // LAST_SAVIORS_POINT_DAMAGE_TOWER_H
