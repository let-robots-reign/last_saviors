#include "player.h"


void Player::increaseCoins(size_t value) { coins_ += value; }

void Player::reduceCoins(size_t value) {
    if (coins_ > value) coins_ -= value;
}
Player::Player(size_t initial_coins)
    : initial_coins_(initial_coins), coins_(initial_coins_) {}
