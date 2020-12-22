#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_H

#include "tower.h"
#include <algorithm>

class AreaDamageTower : public Tower {
   private:
    std::vector<double> damage_radius_per_level_;

   public:
    AreaDamageTower(size_t maxLevel,
                    std::vector<unsigned int> &maxHealthPerLevel,
                    std::vector<unsigned int> &attackCooldownPerLevel,
                    std::vector<unsigned int> &damagePerLevel,
                    std::vector<size_t> &repairCostPerLevel,
                    std::vector<size_t> &upgradeCostPerLevel,
                    std::vector<double> &attackRadiusPerLevel,
                    std::vector<double> &damageRadiusPerLevel,
                    unsigned int currentTime, size_t level = 0, Coordinate position = Coordinate());
    void attack(std::vector<std::shared_ptr<Attackable>> &enemies) override;
    std::vector<std::shared_ptr<Attackable>> findTargets(
        const std::vector<std::shared_ptr<Attackable>> &enemies, Coordinate citadel_position) override;
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_H
