#include "player.h"


void Player::increaseCoins(size_t value) { coins_ += value; }

void Player::reduceCoins(size_t value) {
    if (coins_ > value) coins_ -= value;
}
Player::Player(const PlayerModel& model)
    : model_(model), coins_(model.initialCoins) {}
