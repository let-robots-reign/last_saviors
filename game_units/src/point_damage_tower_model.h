#ifndef LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H
#define LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H

#include <cstddef>

struct PointDamageTowerModel {
    static const int MAX_LEVEL = 5;
    const int MAX_HEALTH_PER_LEVEL[MAX_LEVEL] = {100, 130, 150, 170, 200};
    const double ATTACK_COOLDOWN_PER_LEVEL[MAX_LEVEL] = {2, 1, 1, 0.75, 0.5};
    const int DAMAGE_PER_LEVEL[MAX_LEVEL] = {30, 40, 50, 60, 70};
    const size_t REPAIR_COST_PER_LEVEL[MAX_LEVEL] = {50, 75, 100, 120, 150};
    const size_t UPGRADE_COST_PER_LEVEL[MAX_LEVEL] = {75, 114, 150, 180, 235};
    const double ATTACK_RADIUS_PER_LEVEL[MAX_LEVEL] = {2, 2.5, 3, 3.5, 3.5};
};

#endif  // LAST_SAVIORS_POINT_DAMAGE_TOWER_MODEL_H
