#include "area_damage_tower.h"

#include <utility>


AreaDamageTower::AreaDamageTower(
    size_t max_level, const std::vector<unsigned int> &max_health_per_level,
    const std::vector<unsigned int> &attack_cooldown_per_level,
    const std::vector<unsigned int> &damage_per_level,
    const std::vector<size_t> &repair_cost_per_level,
    const std::vector<size_t> &upgrade_cost_per_level,
    const std::vector<double> &attack_radius_per_level,
    std::vector<double> damage_radius_per_level, unsigned int current_time,
    size_t level, Coordinate position)
    : Tower(max_level, max_health_per_level, attack_cooldown_per_level,
            damage_per_level, repair_cost_per_level, upgrade_cost_per_level,
            attack_radius_per_level, current_time, position, level),
      damage_radius_per_level_(std::move(damage_radius_per_level)) {}


void AreaDamageTower::attack(
    std::vector<std::shared_ptr<Attackable>> &enemies) {
    std::for_each(enemies.begin(), enemies.end(),
                  [&](std::shared_ptr<Attackable> &enemy) {
                      if (canAttack(enemy)) {
                          enemy->reduceHealth(damage_per_level_[level_]);
                      }
                  });
}

std::vector<std::shared_ptr<Attackable>> AreaDamageTower::findTargets(
    const std::vector<std::shared_ptr<Attackable>> &enemies,
    Coordinate citadel_position) {
    std::vector<std::shared_ptr<Attackable>> in_attack_radius;
    std::copy_if(
        enemies.begin(), enemies.end(), std::back_inserter(in_attack_radius),
        [&](const std::shared_ptr<Attackable> &enemy) {
            return this->distance(*enemy) < attack_radius_per_level_[level_] &&
                   canAttack(enemy);
        });
    std::sort(in_attack_radius.begin(), in_attack_radius.end(),
              [&citadel_position](const std::shared_ptr<Attackable> &first,
                                  const std::shared_ptr<Attackable> &second) {
                  return Coordinate::distance(first->getCoordinate(),
                                              citadel_position) <
                         Coordinate::distance(second->getCoordinate(),
                                              citadel_position);
              });
    std::vector<std::shared_ptr<Attackable>> result;
    if (in_attack_radius.size() > 1) {
        size_t last_elem_pos = in_attack_radius.size() - 1;
        for (size_t pos = in_attack_radius.size() - 2;
             pos <= (in_attack_radius.size() - 2) &&
             in_attack_radius[last_elem_pos]->distance(*in_attack_radius[pos]) <
                 damage_radius_per_level_[level_];
             --pos) {
            result.push_back(in_attack_radius[pos]);
        }
        if (result.size() > 2) {
            Coordinate circle_center =
                Coordinate((result[0]->getCoordinate().getX() +
                            result[result.size() - 1]->getCoordinate().getX()) /
                               2,
                           (result[0]->getCoordinate().getY() +
                            result[result.size() - 1]->getCoordinate().getY()) /
                               2);
            result.erase(
                std::remove_if(result.begin(), result.end(),
                               [&](const std::shared_ptr<Attackable> &enemy) {
                                   return Coordinate::distance(
                                              enemy->getCoordinate(),
                                              circle_center) >
                                          damage_radius_per_level_[level_];
                               }),
                result.end());
        }
    } else if (in_attack_radius.size() == 1) {
        result.push_back(in_attack_radius[0]);
    }
    return result;
}
