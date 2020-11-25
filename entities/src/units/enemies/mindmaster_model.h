#ifndef LAST_SAVIORS_MINDMASTER_MODEL_H
#define LAST_SAVIORS_MINDMASTER_MODEL_H

#include <cstddef>

struct MindmasterModel {
    const int MAX_HEALTH = 200;
    const int ATTACK_COOLDOWN = 2;
    const int DAMAGE = 8000;  // todo больше башни
    const double SPEED = 1;
    const size_t COINS_FOR_DEATH = 10;
};

#endif  // LAST_SAVIORS_MINDMASTER_MODEL_H
