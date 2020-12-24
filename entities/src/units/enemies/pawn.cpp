#include "pawn.h"

void Pawn::attack(std::shared_ptr<Attackable> &target, unsigned int current_time) {
    if (isReadyForAttack(current_time) && canAttack(target)) {
        target->reduceHealth(damage_);
        time_of_last_attack_ = current_time;
    }
}


bool Pawn::canAttack(const std::shared_ptr<Attackable> &target) {
    std::shared_ptr<Citadel> temp  = std::dynamic_pointer_cast<Citadel>(target);
    return temp != nullptr;
}

std::shared_ptr<Attackable> Pawn::findTarget(
    std::vector<std::shared_ptr<Attackable>> &possible_targets) {
    auto result = std::find_if(
        possible_targets.begin(), possible_targets.end(),
        [&](const std::shared_ptr<Attackable> &target) { return canAttack(target); });
    return result != possible_targets.end() ? *result : nullptr;
}
Pawn::Pawn(unsigned int current_time, unsigned int max_health, double speed,
           unsigned int attack_cooldown, size_t coins_for_death,
           unsigned int damage, Coordinate position)
    : Enemy(current_time, max_health, speed, attack_cooldown, coins_for_death,
            position),
      damage_(damage) {}
