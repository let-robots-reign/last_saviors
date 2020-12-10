#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_H

#include "area_damage_tower_model.h"
#include "tower.h"

class AreaDamageTower : public Tower {
   private:
    const AreaDamageTowerModel model_;

   public:
    explicit AreaDamageTower(const
        AreaDamageTowerModel& model, time_t current_time,
        Coordinate position = Coordinate(),
        int level = 1);
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_H
