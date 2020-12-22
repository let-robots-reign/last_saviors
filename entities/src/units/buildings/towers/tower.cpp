#include "tower.h"


void Tower::upgrade(Player &player, unsigned int current_time) {
    if (level_ < max_level_ &&
        player.getCoins() >= upgrade_cost_per_level_[level_]) {
        player.reduceCoins(upgrade_cost_per_level_[level_]);
        ++level_;
        time_of_last_attack_ = current_time;
    }
}

void Tower::repair(Player &player, unsigned int current_time) {
    if (level_ < max_level_ &&
        player.getCoins() >= repair_cost_per_level_[level_]) {
        player.reduceCoins(repair_cost_per_level_[level_]);
        setHealth(max_health_per_level_[level_]);
        time_of_last_attack_ = current_time;
    }
}

Tower::Tower(size_t max_level, std::vector<unsigned int> &max_health_per_level,
             std::vector<unsigned int> &attack_cooldown_per_level,
             std::vector<unsigned int> &damage_per_level,
             std::vector<size_t> &repair_cost_per_level,
             std::vector<size_t> &upgrade_cost_per_level,
             std::vector<double> &attack_radius_per_level,
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
    return dynamic_cast<const Enemy *>(&enemy);
}
bool Tower::isReadyForAttack(unsigned int current_time) {
    return current_time >=
           time_of_last_attack_ + attack_cooldown_per_level_[level_];
}
