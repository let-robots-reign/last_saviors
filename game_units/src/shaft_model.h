#ifndef LAST_SAVIORS_SHAFT_MODEL_H
#define LAST_SAVIORS_SHAFT_MODEL_H

struct ShaftModel {
    const int MAX_LEVEL = 5;
    const time_t COOLDOWN_PER_LEVEL[MAX_LEVEL] = {60, 50, 40, 30, 20};
    const size_t AMOUNT_OF_COINS_PER_LEVEL[MAX_LEVEL] = {75, 100, 125, 150,
                                                         175};
    const size_t UPGRADE_COST_PER_LEVEL[MAX_LEVEL] = {125, 200, 300, 400, 500};
};

#endif  // LAST_SAVIORS_SHAFT_MODEL_H
