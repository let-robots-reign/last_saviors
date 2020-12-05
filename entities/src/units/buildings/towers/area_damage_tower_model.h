#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H

#include <cstddef>
#include <vector>

struct AreaDamageTowerModel {
    const int MAX_LEVEL;
    const std::vector<int> MAX_HEALTH_PER_LEVEL;
    const std::vector<double> ATTACK_COOLDOWN_PER_LEVEL;
    const std::vector<int> DAMAGE_PER_LEVEL;
    const std::vector<size_t> REPAIR_COST_PER_LEVEL;
    const std::vector<size_t> UPGRADE_COST_PER_LEVEL;
    const std::vector<double> ATTACK_RADIUS_PER_LEVEL;
    const std::vector<double> DAMAGE_RADIUS_PER_LEVEL;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H
