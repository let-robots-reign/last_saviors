#include "pawn.h"

void Pawn::attack(Attackable &target, time_t current_time) {
    if (isReadyForAttack(current_time) && canAttack(target)) {
        target.reduceHealth(model_.damage);
        time_of_last_attack_ = current_time;
    }
}

bool Pawn::isReadyForAttack(time_t current_time) {
    return current_time - time_of_last_attack_ >= model_.attackCooldown;
}

bool Pawn::canAttack(const Attackable &target) {
    return typeid(target).hash_code() == typeid(Citadel).hash_code();
}

Attackable *Pawn::findTarget(std::list<Attackable> &possible_targets) {
    return &*std::find_if(
        possible_targets.begin(), possible_targets.end(),
        [&](const Attackable &target) { return canAttack(target); });
}

Pawn::Pawn(const PawnModel &model, time_t current_time, Coordinate position)
    : Enemy(model.maxHealth, current_time, position), model_(model) {}
