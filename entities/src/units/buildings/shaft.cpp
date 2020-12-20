#include "shaft.h"

bool Shaft::canGetCoins(unsigned int current_time) const {
    return time_of_last_usage_ + current_time[level_] <=
           current_time;
}
void Shaft::getCoins(Player& player, unsigned int current_time) {
    if (canGetCoins(current_time)) {
        player.increaseCoins(amount_of_coins_per_level_[level_]);
        time_of_last_usage_ = current_time;
    }
}
void Shaft::upgrade(Player& player, unsigned int current_time) {
    if (level_ < max_level_ &&
        player.getCoins() > upgrade_cost_per_level_[level_]) {
        player.reduceCoins(upgrade_cost_per_level_[level_]);
        ++level_;
        time_of_last_usage_ = current_time;
    }
}
Shaft::Shaft(int max_level, std::vector<unsigned int> &cooldown_per_level,
             std::vector<size_t> &amount_of_coins_per_level,
             std::vector<size_t> &upgrade_cost_per_level,
             unsigned int current_time, Coordinate position, int level)
    : Unit(position),
      time_of_last_usage_(current_time),
      level_(level),
      max_level_(max_level),
      cooldown_per_level_(cooldown_per_level),
      amount_of_coins_per_level_(amount_of_coins_per_level),
      upgrade_cost_per_level_(upgrade_cost_per_level) {}
