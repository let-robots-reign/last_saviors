#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H

#include <cstddef>
#include <vector>

struct AreaDamageTowerModel {

    const int maxLevel;
    const std::vector<int> maxHealthPerLevel;
    const std::vector<int> attackCooldownPerLevel;
    const std::vector<int> damagePerLevel;
    const std::vector<size_t> repairCostPerLevel;
    const std::vector<size_t> upgradeCostPerLevel;
    const std::vector<double> attackRadiusPerLevel;
    const std::vector<double> damageRadiusPerLevel;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H
