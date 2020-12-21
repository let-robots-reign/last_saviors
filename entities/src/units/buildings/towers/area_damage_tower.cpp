#include "area_damage_tower.h"



AreaDamageTower::AreaDamageTower(
    size_t maxLevel, std::vector<unsigned int> maxHealthPerLevel,
    std::vector<unsigned int> attackCooldownPerLevel,
    std::vector<unsigned int> damagePerLevel,
    std::vector<size_t> repairCostPerLevel,
    std::vector<size_t> upgradeCostPerLevel,
    std::vector<double> attackRadiusPerLevel,
    std::vector<double> damageRadiusPerLevel, unsigned int currentTime,
    int level, Coordinate position): Tower(maxLevel, maxHealthPerLevel, attackCooldownPerLevel, damagePerLevel,
                                           repairCostPerLevel, upgradeCostPerLevel, attackRadiusPerLevel,
                                           currentTime, position, level),
                                     damage_radius_per_level_(damageRadiusPerLevel) {}
void AreaDamageTower::attack(std::vector<Attackable>& enemies) {
    std::for_each(enemies.begin(), enemies.end(), [&](Attackable &enemy) {
      if (canAttack(enemy)) {
          enemy.reduceHealth(damage_per_level_[level_]);
      }
    });
}

std::vector<Attackable> AreaDamageTower::findTargets(
    const std::vector<Attackable>& enemies, Coordinate citadel_position) {
        std::vector<Attackable> in_attack_radius;
        std::copy_if(
            enemies.begin(), enemies.end(), std::back_inserter(in_attack_radius),
            [&](const Attackable &enemy) {
              return this->distance(enemy) < attack_radius_per_level_[level_] &&
                     canAttack(enemy);
            });
        std::sort(in_attack_radius.begin(), in_attack_radius.end(), [&citadel_position](const Attackable &first,
                                                                                        const Attackable &second) {
          return Coordinate::distance(first.getCoordinate(),
                                      citadel_position) <
                 Coordinate::distance(second.getCoordinate(),
                                      citadel_position);
        });
        std::vector<Attackable> result;
//        if (!in_attack_radius.empty()) {
//            while ()
//        }
        return result;

}

