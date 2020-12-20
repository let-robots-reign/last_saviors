#include "point_damage_tower.h"


void PointDamageTower::attack(std::vector<Attackable> &enemies) {
    std::for_each(enemies.begin(), enemies.end(), [&](Attackable &enemy) {
        if (canAttack(enemy)) {
            enemy.reduceHealth(damage_per_level_[level_]);
        }
    });
}

PointDamageTower::PointDamageTower(
    size_t max_level, std::vector<unsigned int> &max_health_per_level,
    std::vector<unsigned int> &attack_cooldown_per_level,
    std::vector<unsigned int> &damage_per_level,
    std::vector<size_t> &repair_cost_per_level,
    std::vector<size_t> &upgrade_cost_per_level,
    std::vector<double> &attack_radius_per_level, unsigned int current_time,
    Coordinate position, int level)
    : Tower(max_level, max_health_per_level, attack_cooldown_per_level,
            damage_per_level, repair_cost_per_level, upgrade_cost_per_level,
            attack_radius_per_level, current_time, position, level) {}
