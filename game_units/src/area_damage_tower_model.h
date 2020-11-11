#ifndef LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H
#define LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H

struct AreaDamageTowerModel {
    const int MAX_LEVEL = 5;
    const int MAX_HEALTH_PER_LEVEL[MAX_LEVEL] = {100, 130, 150, 170, 200};
    const double ATTACK_RATE_PER_LEVEL[MAX_LEVEL] = {
        0.5, 1, 1, 1, 1};  // todo уточнить момент со скорострельностью
    const int DAMAGE_PER_LEVEL[MAX_LEVEL] = {30, 40, 50, 60, 70};
    const int REPAIR_COST_PER_LEVEL[MAX_LEVEL] = {50, 75, 100, 120, 150};
    const int UPGRADE_COST_PER_LEVEL[MAX_LEVEL] = {75, 114, 150, 180, 235};
    const double ATTACK_RADIUS_PER_LEVEL[MAX_LEVEL] = {2, 2.5, 3, 3.5, 3.5};
    const double DAMAGE_RADIUS_PER_LEVEL[MAX_LEVEL] = {0.5, 0.75, 1, 1.25, 1.5};
};

#endif  // LAST_SAVIORS_AREA_DAMAGE_TOWER_MODEL_H
