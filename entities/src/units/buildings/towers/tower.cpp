#include "tower.h"


void Tower::upgrade(Player &player, unsigned int current_time) {
    if (upgrade_cost_per_level_.size() > level_ && level_ < max_level_ &&
        player.getCoins() >= upgrade_cost_per_level_[level_]) {
        player.reduceCoins(upgrade_cost_per_level_[level_]);
        ++level_;
        time_of_last_attack_ = current_time;
    }
}

void Tower::repair(Player &player, unsigned int current_time) {
    if (repair_cost_per_level_.size() > level_ &&
        max_health_per_level_.size() > level_ &&
        player.getCoins() >= repair_cost_per_level_[level_]) {
        player.reduceCoins(repair_cost_per_level_[level_]);
        setHealth(max_health_per_level_[level_]);
        time_of_last_attack_ = current_time;
    }
}

Tower::Tower(size_t max_level,
             const std::vector<unsigned int> &max_health_per_level,
             const std::vector<unsigned int> &attack_cooldown_per_level,
             const std::vector<unsigned int> &damage_per_level,
             const std::vector<size_t> &repair_cost_per_level,
             const std::vector<size_t> &upgrade_cost_per_level,
             const std::vector<double> &attack_radius_per_level,
             unsigned int current_time, Coordinate position, size_t level)
    : Attackable(max_health_per_level[level], position),
      time_of_last_attack_(current_time),
      level_(level),
      max_level_(max_level),
      max_health_per_level_(max_health_per_level),
      attack_cooldown_per_level_(attack_cooldown_per_level),
      damage_per_level_(damage_per_level),
      repair_cost_per_level_(repair_cost_per_level),
      upgrade_cost_per_level_(upgrade_cost_per_level),
      attack_radius_per_level_(attack_radius_per_level) {}

bool Tower::canAttack(const std::shared_ptr<Attackable> &enemy) {
    auto temp = std::dynamic_pointer_cast<const Enemy>(enemy);
    return temp != nullptr;
}
bool Tower::isReadyForAttack(unsigned int current_time) {
    return attack_cooldown_per_level_.size() > level_ &&
           current_time >=
               time_of_last_attack_ + attack_cooldown_per_level_[level_];
}
