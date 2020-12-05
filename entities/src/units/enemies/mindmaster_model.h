#ifndef LAST_SAVIORS_MINDMASTER_MODEL_H
#define LAST_SAVIORS_MINDMASTER_MODEL_H

#include <cstddef>

struct MindmasterModel {
    MindmasterModel();
    const int MAX_HEALTH;
    const int DAMAGE;
    const double SPEED;
    const time_t ATTACK_COOLDOWN;
    const size_t COINS_FOR_DEATH;
};

#endif  // LAST_SAVIORS_MINDMASTER_MODEL_H
