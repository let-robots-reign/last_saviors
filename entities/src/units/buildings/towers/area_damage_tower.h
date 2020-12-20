#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_H

#include "tower.h"

class AreaDamageTower : public Tower {
   private:
    std::vector<double> damage_radius_per_level_;

   public:
    void attack(std::vector<Attackable> &enemies) override;
    std::vector<Attackable> findTargets(
        const std::vector<Attackable> &enemies) override;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_H
