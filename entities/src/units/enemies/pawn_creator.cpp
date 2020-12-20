#include "pawn_creator.h"

bool PawnCreator::validityConfigurationCheck(unsigned int max_health,
                                             unsigned int damage, double speed,
                                             unsigned int attack_cooldown,
                                             size_t coins_for_death) {
    return max_health > 0 && damage > 0 && speed > 0 && attack_cooldown > 0 &&
           coins_for_death > 0;
}


void PawnCreator::changeConfiguration(unsigned int max_health,
                                      unsigned int damage, double speed,
                                      unsigned int attack_cooldown,
                                      size_t coins_for_death) noexcept(false) {
    if (!validityConfigurationCheck(max_health, speed, attack_cooldown,
                                    coins_for_death)) {
        throw std::invalid_argument("Used non-positive values");
    }
    max_health_ = max_health;
    speed_ = speed;
    attack_cooldown_ = attack_cooldown;
    coins_for_death_ = coins_for_death;
    damage_ = damage;
}
PawnCreator::PawnCreator(unsigned int max_health, unsigned int damage,
                         double speed, unsigned int attack_cooldown,
                         size_t coins_for_death) noexcept(false) {
    try {
        changeConfiguration(max_health, damage, speed, attack_cooldown,
                            coins_for_death);
    } catch (...) {
        throw;
    }
}

std::shared_ptr<Enemy> PawnCreator::createEnemy(unsigned int current_time,
                                                Coordinate position) const {
    return std::make_shared<Pawn>(current_time, max_health_, speed_,
                                  attack_cooldown_, coins_for_death_, damage_,
                                  position);
}
