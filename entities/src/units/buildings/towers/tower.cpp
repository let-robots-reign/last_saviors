#include "tower.h"

Tower::Tower(int health, time_t current_time, Coordinate position, int level)
    : Attackable(health, position),
      time_of_last_attack_(current_time),
      level_(level) {}
