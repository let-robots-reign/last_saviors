#include "pawn_creator.h"

std::shared_ptr<Enemy> PawnCreator::createEnemy(time_t current_time,
                                                Coordinate position) const {
    return std::make_shared<Pawn>(model_, current_time, position);
}

PawnCreator::PawnCreator(unsigned int maxHealth, unsigned int damage,
                         double speed, unsigned int attackCooldown,
                         size_t coinsForDeath) {
    try {
        changeConfiguration(maxHealth, damage, speed, attackCooldown,
                            coinsForDeath);
    } catch (...) {
        throw;
    }
}

bool PawnCreator::validityConfigurationCheck(unsigned int maxHealth,
                                             unsigned int damage, double speed,
                                             unsigned int attackCooldown,
                                             size_t coinsForDeath) {
    return maxHealth > 0 && damage > 0 && speed > 0 && attackCooldown > 0 &&
           coinsForDeath > 0;
}
void PawnCreator::changeConfiguration(unsigned int maxHealth,
                                      unsigned int damage, double speed,
                                      unsigned int attackCooldown,
                                      size_t coinsForDeath) {
    if (!validityConfigurationCheck(maxHealth, damage, speed, attackCooldown,
                                    coinsForDeath)) {
        throw std::invalid_argument("Used non-positive values");
    }
    model_ = {maxHealth, damage, speed, attackCooldown, coinsForDeath};
}
