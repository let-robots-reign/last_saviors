
#include "mindmaster_creator.h"
bool MindmasterCreator::validityConfigurationCheck(unsigned int maxHealth,
                                                   double speed,
                                                   unsigned int attackCooldown,
                                                   size_t coinsForDeath) {
    return maxHealth > 0 && speed > 0 && attackCooldown > 0 &&
           coinsForDeath > 0;
}
MindmasterCreator::MindmasterCreator(unsigned int maxHealth, double speed,
                                     unsigned int attackCooldown,
                                     size_t coinsForDeath) noexcept(false) {
    try {
        changeConfiguration(maxHealth, speed, attackCooldown,
                            coinsForDeath);
    } catch (...) {
        throw;
    }
}
void MindmasterCreator::changeConfiguration(
    unsigned int maxHealth, double speed, unsigned int attackCooldown,
    size_t coinsForDeath) noexcept(false) {
    if (!validityConfigurationCheck(maxHealth, speed, attackCooldown,
                                    coinsForDeath)) {
        throw std::invalid_argument("Used non-positive values");
    }
    model_ = {maxHealth, speed, attackCooldown, coinsForDeath};
}
std::shared_ptr<Enemy> MindmasterCreator::createEnemy(
    time_t current_time, Coordinate position) const {
    return std::make_shared<Mindmaster>(model_, current_time, position);
}
