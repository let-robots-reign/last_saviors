#include "area_damage_tower.h"

AreaDamageTower::AreaDamageTower(AreaDamageTowerModel *model,
                                 Coordinate position, int level)
    : Tower(model->MAX_HEALTH_PER_LEVEL[level], position, level),
      model_(model) {}

void AreaDamageTower::attack(Enemy *targets) {}
bool AreaDamageTower::canAttack() { return true; }
Enemy *AreaDamageTower::findTargets() { return nullptr; }
