#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H

#include <cstddef>
#include <vector>

struct AreaDamageTowerModel {

    int maxLevel;
    std::vector<int> maxHealthPerLevel;
    std::vector<unsigned int> attackCooldownPerLevel;
    std::vector<int> damagePerLevel;
    std::vector<size_t> repairCostPerLevel;
    std::vector<size_t> upgradeCostPerLevel;
    std::vector<double> attackRadiusPerLevel;
    std::vector<double> damageRadiusPerLevel;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H
