#ifndef LAST_SAVIORS_POINT_DAMAGE_TOWER_H
#define LAST_SAVIORS_POINT_DAMAGE_TOWER_H

#include "point_damage_tower_model.h"
#include "tower.h"

class PointDamageTower : public Tower {
   private:
    const PointDamageTowerModel* model_;

   public:
    PointDamageTower(const PointDamageTowerModel* model, time_t current_time,
                     Coordinate position = Coordinate(), int level = 1);
};

#endif  // LAST_SAVIORS_POINT_DAMAGE_TOWER_H
