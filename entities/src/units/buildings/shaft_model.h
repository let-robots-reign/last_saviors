#ifndef LAST_SAVIORS_SHAFT_MODEL_H
#define LAST_SAVIORS_SHAFT_MODEL_H

#include <cstddef>
#include <vector>

struct ShaftModel {
    int maxLevel;
    std::vector<unsigned int> cooldownPerLevel;
    std::vector<size_t> amountOfCoinsPerLevel;
    std::vector<size_t> upgradeCostPerLevel;
};

#endif  // LAST_SAVIORS_SHAFT_MODEL_H
