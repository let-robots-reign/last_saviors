#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_H

#include <algorithm>

#include "tower.h"

class AreaDamageTower : public Tower {
   private:
    std::vector<double> damage_radius_per_level_;

   public:
    AreaDamageTower(size_t max_level,
                    const std::vector<unsigned int> &max_health_per_level,
                    const std::vector<unsigned int> &attack_cooldown_per_level,
                    const std::vector<unsigned int> &damage_per_level,
                    const std::vector<size_t> &repair_cost_per_level,
                    const std::vector<size_t> &upgrade_cost_per_level,
                    const std::vector<double> &attack_radius_per_level,
                    std::vector<double> damage_radius_per_level,
                    unsigned int current_time, size_t level = 0,
                    Coordinate position = Coordinate());
    void attack(std::vector<std::shared_ptr<Attackable>> &enemies) override;
    std::vector<std::shared_ptr<Attackable>> findTargets(
        const std::vector<std::shared_ptr<Attackable>> &enemies,
        Coordinate citadel_position) override;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_H
