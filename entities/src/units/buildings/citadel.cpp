#include "citadel.h"

Citadel::Citadel(const CitadelModel *model, Coordinate position)
    : AttackableBuilding(model->MAX_HEALTH, position), model_(model) {}