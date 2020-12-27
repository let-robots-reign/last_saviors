#include "mindmaster_creator.h"

bool MindmasterCreator::validityConfigurationCheck(unsigned int max_health,
                                                   double speed,
                                                   unsigned int attack_cooldown,
                                                   size_t coins_for_death) {
    return max_health > 0 && speed > 0 && attack_cooldown > 0 &&
           coins_for_death > 0;
}
MindmasterCreator::MindmasterCreator(unsigned int max_health, double speed,
                                     unsigned int attack_cooldown,
                                     size_t coins_for_death) noexcept(false) {
    try {
        changeConfiguration(max_health, speed, attack_cooldown,
                            coins_for_death);
    } catch (...) {
        throw;
    }
}
void MindmasterCreator::changeConfiguration(
    unsigned int max_health, double speed, unsigned int attack_cooldown,
    size_t coins_for_death) noexcept(false) {
    if (!validityConfigurationCheck(max_health, speed, attack_cooldown,
                                    coins_for_death)) {
        throw std::invalid_argument("Used non-positive values");
    }
    max_health_ = max_health;
    speed_ = speed;
    attack_cooldown_ = attack_cooldown;
    coins_for_death_ = coins_for_death;
}

std::shared_ptr<Enemy> MindmasterCreator::createEnemy(
    unsigned int current_time, Coordinate position) const {
    return std::make_shared<Mindmaster>(current_time, max_health_, speed_,
                                        attack_cooldown_, coins_for_death_,
                                        position);
}
