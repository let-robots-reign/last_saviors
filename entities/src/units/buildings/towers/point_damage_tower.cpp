#include "point_damage_tower.h"

PointDamageTower::PointDamageTower(const PointDamageTowerModel& model,
                                   time_t current_time, Coordinate position,
                                   int level)
    : Tower(model.maxHealthPerLevel[level], current_time, position, level),
      model_(model) {}
