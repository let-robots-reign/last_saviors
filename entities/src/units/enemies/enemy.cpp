#include "enemy.h"

Enemy::Enemy(unsigned int current_time, unsigned int max_health, double speed,
             unsigned int attack_cooldown, size_t coins_for_death,
             Coordinate position)
    : Attackable(max_health, position),
      time_of_last_attack_(current_time),
      max_health_(max_health),
      speed_(speed),
      attack_cooldown_(attack_cooldown),
      coins_for_death_(coins_for_death) {}

bool Enemy::isReadyForAttack(unsigned int current_time) const {
    return current_time >= time_of_last_attack_ + attack_cooldown_;
}
