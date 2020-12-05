#ifndef LAST_SAVIORS_SHAFT_MODEL_H
#define LAST_SAVIORS_SHAFT_MODEL_H

#include <cstddef>
#include <vector>

struct ShaftModel {
    const int MAX_LEVEL;
    const std::vector<time_t> COOLDOWN_PER_LEVEL;
    const std::vector<size_t> AMOUNT_OF_COINS_PER_LEVEL;
    const std::vector<size_t> UPGRADE_COST_PER_LEVEL;
};

#endif  // LAST_SAVIORS_SHAFT_MODEL_H
