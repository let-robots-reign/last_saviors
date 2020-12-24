#include "point_damage_tower.h"


void PointDamageTower::attack(
    std::vector<std::shared_ptr<Attackable>> &enemies) {
    if (!enemies.empty() && canAttack(enemies[0])) {
        enemies[0]->reduceHealth(damage_per_level_[level_]);
    }
}

PointDamageTower::PointDamageTower(
    size_t max_level, const std::vector<unsigned int> &max_health_per_level,
    const std::vector<unsigned int> &attack_cooldown_per_level,
    const std::vector<unsigned int> &damage_per_level,
    const std::vector<size_t> &repair_cost_per_level,
    const std::vector<size_t> &upgrade_cost_per_level,
    const std::vector<double> &attack_radius_per_level, unsigned int current_time,
    Coordinate position, size_t level)
    : Tower(max_level, max_health_per_level, attack_cooldown_per_level,
            damage_per_level, repair_cost_per_level, upgrade_cost_per_level,
            attack_radius_per_level, current_time, position, level) {}

std::vector<std::shared_ptr<Attackable>> PointDamageTower::findTargets(
    const std::vector<std::shared_ptr<Attackable>> &enemies, Coordinate citadel_position) {
    std::vector<std::shared_ptr<Attackable>> in_attack_radius;
    std::copy_if(
        enemies.begin(), enemies.end(), std::back_inserter(in_attack_radius),
        [&](const std::shared_ptr<Attackable> &enemy) {
            return this->distance(*enemy) < attack_radius_per_level_[level_] &&
                   canAttack(enemy);
        });
    std::vector<std::shared_ptr<Attackable>> result;
    if (!in_attack_radius.empty()) {
        result.push_back(*std::min_element(
            in_attack_radius.begin(), in_attack_radius.end(),
            [&citadel_position](const std::shared_ptr<Attackable> &first,
                                const std::shared_ptr<Attackable> &second) {
                return Coordinate::distance(first->getCoordinate(),
                                            citadel_position) <
                       Coordinate::distance(second->getCoordinate(),
                                            citadel_position);
            }));
    }
    return result;
}
