#ifndef LAST_SAVIORS_PAWNMODEL_H
#define LAST_SAVIORS_PAWNMODEL_H

#include <cstddef>

struct PawnModel {
    const int MAX_HEALTH = 100;
    const double ATTACK_COOLDOWN = 0.5;
    const int DAMAGE = 15;
    const double SPEED = 3;
    const size_t COINS_FOR_DEATH = 5;
};

#endif  // LAST_SAVIORS_PAWNMODEL_H
