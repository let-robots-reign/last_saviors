#ifndef LAST_SAVIORS_PAWNMODEL_H
#define LAST_SAVIORS_PAWNMODEL_H

#include <cstddef>

struct PawnModel {
    PawnModel();
    const int kMaxHealth;
    const int kDamage;
    const double kSpeed;
    const time_t
        kAttackCooldown;  // todo attack cooldown too long but time in seconds
    const size_t kCoinsForDeath;
};

#endif  // LAST_SAVIORS_PAWNMODEL_H
