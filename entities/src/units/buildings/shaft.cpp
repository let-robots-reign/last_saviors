#include "shaft.h"

#include <utility>

// void Shaft::getCoins(Player *player, time_t current_time) {
//    if (canGetCoins(current_time)) {
//        player->increaseCoins(model_->amountOfCoinsPerLevel[level_]);
//        time_of_last_usage_ = current_time;
//    }
//}
// bool Shaft::canGetCoins(time_t current_time) {
//    return current_time - time_of_last_usage_ >
//           model_->cooldownPerLevel[level_];
//}
// Shaft::Shaft(const ShaftModel *model, time_t current_time, Coordinate
// position,
//             int level)
//    : Unit(position),
//      time_of_last_usage_(current_time),
//      level_(level),
//      model_(model) {}
Shaft::Shaft(ShaftModel model, unsigned int current_time, Coordinate position,
             int level)
    : Unit(position),
      time_of_last_usage_(current_time),
      level_(level),
      model_(std::move(model)) {}

bool Shaft::canGetCoins(unsigned int current_time) const {
    return time_of_last_usage_ + model_.cooldownPerLevel[level_] <=
           current_time;
}
void Shaft::getCoins(Player& player, unsigned int current_time) {
    if (canGetCoins(current_time)) {
        player.increaseCoins(model_.amountOfCoinsPerLevel[level_]);
        time_of_last_usage_ = current_time;
    }
}
void Shaft::upgrade(Player& player, unsigned int current_time) {
    if (level_ < model_.maxLevel && player.getCoins() > model_.upgradeCostPerLevel[level_]){
        player.reduceCoins(model_.upgradeCostPerLevel[level_]);
        ++level_;
        time_of_last_usage_ = current_time;
    }
}
