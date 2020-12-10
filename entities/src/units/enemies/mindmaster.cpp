#include "mindmaster.h"

void Mindmaster::attack(Attackable &target, time_t current_time) {
    if (isReadyForAttack(current_time) && canAttack(target)) {
        target.reduceHealth(target.getHealth() / 2);
        time_of_last_attack_ = current_time;
    }
}

Attackable *Mindmaster::findTarget(std::list<Attackable> &possible_targets) {
    return &*std::max_element(
        possible_targets.begin(), possible_targets.end(),
        [&](const Attackable &target1, const Attackable &target2) {
            if (!canAttack(target1)) return true;
            if (!canAttack(target2)) return false;
            return distance(target1) > distance(target2);
        });
}

bool Mindmaster::isReadyForAttack(time_t current_time) {
    return current_time - time_of_last_attack_ >= model_.attackCooldown;
}

Mindmaster::Mindmaster(const MindmasterModel &model, time_t current_time,
                       Coordinate position)
    : Enemy(model.maxHealth, current_time, position), model_(model) {}

bool Mindmaster::canAttack(const Attackable &target) {
    return dynamic_cast<const Tower *>(&target);
}
