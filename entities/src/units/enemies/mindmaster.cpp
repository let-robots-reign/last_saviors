#include "mindmaster.h"

void Mindmaster::attack(std::shared_ptr<Attackable> &target, unsigned int current_time) {
    if (isReadyForAttack(current_time) && canAttack(target)) {
        target->reduceHealth(target->getHealth() / 2);
        time_of_last_attack_ = current_time;
    }
}

std::shared_ptr<Attackable> Mindmaster::findTarget(
    std::vector<std::shared_ptr<Attackable>> &possible_targets) {
    return *std::max_element(
        possible_targets.begin(), possible_targets.end(),
        [&](const std::shared_ptr<Attackable> &target1, const std::shared_ptr<Attackable> &target2) {
            if (!canAttack(target1)) return true;
            if (!canAttack(target2)) return false;
            return distance(*target1) > distance(*target2);
        });
}


bool Mindmaster::canAttack(const std::shared_ptr<Attackable> &target) {
    std::shared_ptr<Tower> temp  = std::dynamic_pointer_cast<Tower>(target);
    return temp != nullptr;
}
Mindmaster::Mindmaster(unsigned int current_time, unsigned int max_health,
                       double speed, unsigned int attack_cooldown,
                       size_t coins_for_death, Coordinate position)
    : Enemy(current_time, max_health, speed, attack_cooldown, coins_for_death,
            position) {}
