#include "citadel.h"

Citadel::Citadel(const CitadelModel& model, Coordinate position)
    : Attackable(model.maxHealth, position), model_(model) {}
