#ifndef LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H
#define LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H

#include <vector>

struct PointDamageTowerModel {
    size_t maxLevel;
    std::vector<int> maxHealthPerLevel;
    std::vector<unsigned int> attackCooldownPerLevel;
    std::vector<int> damagePerLevel;
    std::vector<size_t> repairCostPerLevel;
    std::vector<size_t> upgradeCostPerLevel;
    std::vector<double> attackRadiusPerLevel;
};

#endif  // LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H
