#include "pawn.h"


Pawn::Pawn(const std::shared_ptr<PawnModel> &model, time_t current_time,
           Coordinate position)
    : Enemy(model->kMaxHealth, current_time, position), model_(model) {}

void Pawn::attack(Attackable &target, time_t current_time) {
    if (isReadyForAttack(current_time) && canAttack(target)) {
        target.reduceHealth(model_->kDamage);
    }
}

bool Pawn::isReadyForAttack(time_t current_time) {
    return current_time - time_of_last_attack_ >= model_->kAttackCooldown;
}
bool Pawn::canAttack(const Attackable &target) {
    return typeid(target) == typeid(Citadel);
}
Attackable *Pawn::findTarget(std::list<Attackable> &possible_targets) {
    return &*(std::find_if(possible_targets.begin(), possible_targets.end(),
                           [](const Attackable &target) {
                               return typeid(target) == typeid(Citadel);
                           }));
}
