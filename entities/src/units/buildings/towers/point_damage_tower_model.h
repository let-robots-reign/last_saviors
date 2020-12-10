#ifndef LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H
#define LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H

#include <vector>

struct PointDamageTowerModel {
    const size_t maxLevel;
    const std::vector<int> maxHealthPerLevel;
    const std::vector<int> attackCooldownPerLevel;
    const std::vector<int> damagePerLevel;
    const std::vector<size_t> repairCostPerLevel;
    const std::vector<size_t> upgradeCostPerLevel;
    const std::vector<double> attackRadiusPerLevel;
};

#endif  // LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H
