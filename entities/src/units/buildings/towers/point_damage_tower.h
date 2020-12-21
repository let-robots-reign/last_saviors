#ifndef LAST_SAVIORS_POINT_DAMAGE_TOWER_H
#define LAST_SAVIORS_POINT_DAMAGE_TOWER_H

#include "tower.h"
#include <algorithm>

class PointDamageTower : public Tower {
   public:
    PointDamageTower(size_t max_level,
                     std::vector<unsigned int> max_health_per_level,
                     std::vector<unsigned int> attack_cooldown_per_level,
                     std::vector<unsigned int> damage_per_level,
                     std::vector<size_t> repair_cost_per_level,
                     std::vector<size_t> upgrade_cost_per_level,
                     std::vector<double> attack_radius_per_level,
                     unsigned int current_time, Coordinate position,
                     int level);
    void attack(std::vector<Attackable> &enemies) override;
    std::vector<Attackable> findTargets(const std::vector<Attackable> &enemies, Coordinate citadel_position) override;
};

#endif  // LAST_SAVIORS_POINT_DAMAGE_TOWER_H
