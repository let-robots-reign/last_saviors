#include "pawn.h"

void Pawn::attack(Attackable &target, unsigned int current_time) {
    if (isReadyForAttack(current_time) && canAttack(target)) {
        target.reduceHealth(damage_);
        time_of_last_attack_ = current_time;
    }
}


bool Pawn::canAttack(const Attackable &target) {
    return typeid(target).hash_code() == typeid(Citadel).hash_code();
}

Attackable *Pawn::findTarget(std::vector<Attackable> &possible_targets) {
    return &*std::find_if(
        possible_targets.begin(), possible_targets.end(),
        [&](const Attackable &target) { return canAttack(target); });
}
Pawn::Pawn(unsigned int current_time, unsigned int max_health, double speed,
           unsigned int attack_cooldown, size_t coins_for_death,
           unsigned int damage, Coordinate position)
    : Enemy(current_time, max_health, speed, attack_cooldown, coins_for_death,
            position),
      damage_(damage) {}
