
#include "area_damage_tower_creator.h"


AreaDamageTowerCreator::AreaDamageTowerCreator(
    int level, size_t max_level, std::vector<unsigned int> max_health_per_level,
    std::vector<unsigned int> attack_cooldown_per_level,
    std::vector<unsigned int> damage_per_level,
    std::vector<size_t> repair_cost_per_level,
    std::vector<size_t> upgrade_cost_per_level,
    std::vector<double> attack_radius_per_level,
    std::vector<double> damage_radius_per_level)
    : level_(level),
      max_level_(max_level),
      max_health_per_level_(max_health_per_level),
      attack_cooldown_per_level_(attack_cooldown_per_level),
      damage_per_level_(damage_per_level),
      repair_cost_per_level_(repair_cost_per_level),
      upgrade_cost_per_level_(upgrade_cost_per_level),
      attack_radius_per_level_(attack_radius_per_level),
      damage_radius_per_level_(damage_radius_per_level) {}


std::shared_ptr<Tower> AreaDamageTowerCreator::createTower(
    unsigned int current_time, Coordinate position) const {
    return std::make_shared<AreaDamageTower>(
        max_level_, max_health_per_level_, attack_cooldown_per_level_,
        damage_per_level_, repair_cost_per_level_, upgrade_cost_per_level_,
        attack_radius_per_level_, damage_radius_per_level_, current_time,
        level_, position);
}


void AreaDamageTowerCreator::changeConfiguration(
    int level, size_t max_level,
    std::vector<unsigned int>& max_health_per_level,
    std::vector<unsigned int>& attack_cooldown_per_level,
    std::vector<unsigned int>& damage_per_level,
    std::vector<size_t>& repair_cost_per_level,
    std::vector<size_t>& upgrade_cost_per_level,
    std::vector<double>& attack_radius_per_level,
    std::vector<double>& damage_radius_per_level) {
    level_ = level;
    max_level_ = max_level;
    max_health_per_level_ = max_health_per_level;
    attack_cooldown_per_level_ = attack_cooldown_per_level;
    damage_per_level_ = damage_per_level;
    repair_cost_per_level_ = repair_cost_per_level;
    upgrade_cost_per_level_ = upgrade_cost_per_level;
    attack_radius_per_level_ = attack_radius_per_level;
    damage_radius_per_level_ = damage_radius_per_level;
}
