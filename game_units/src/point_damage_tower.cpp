#include "point_damage_tower.h"

PointDamageTower::PointDamageTower(const PointDamageTowerModel *model,
                                   Coordinate position, int level)
    : Tower(model->MAX_HEALTH_PER_LEVEL[level], position, level),
      model_(model) {}

void PointDamageTower::attack(Enemy *targets) {}
Enemy *PointDamageTower::findTargets() { return nullptr; }
bool PointDamageTower::canAttack() { return true; }