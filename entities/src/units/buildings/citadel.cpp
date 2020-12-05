#include "citadel.h"

Citadel::Citadel(const CitadelModel *model, Coordinate position)
    : Attackable(model->MAX_HEALTH, position), model_(model) {}
