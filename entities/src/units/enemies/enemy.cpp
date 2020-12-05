#include "enemy.h"

Enemy::Enemy(int health, time_t current_time, Coordinate position)
    : Attackable(health, position), time_of_last_attack_(current_time) {}
