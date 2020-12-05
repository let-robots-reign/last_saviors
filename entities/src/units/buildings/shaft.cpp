#include "shaft.h"

void Shaft::getCoins(Player *player, time_t current_time) {
    if (canGetCoins(current_time)) {
        player->increaseCoins(model_->AMOUNT_OF_COINS_PER_LEVEL[level_]);
        time_of_last_usage_ = current_time;
    }
}
bool Shaft::canGetCoins(time_t current_time) {
    return current_time - time_of_last_usage_ >
           model_->COOLDOWN_PER_LEVEL[level_];
}
Shaft::Shaft(const ShaftModel *model, time_t current_time, Coordinate position,
             int level)
    : Unit(position),
      time_of_last_usage_(current_time),
      level_(level),
      model_(model) {}
