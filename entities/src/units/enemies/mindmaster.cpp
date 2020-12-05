#include "mindmaster.h"

void Mindmaster::attack(Attackable &target, time_t current_time) {}
Attackable *Mindmaster::findTarget(std::list<Attackable> &possible_targets) {
    return nullptr;
}
bool Mindmaster::isReadyForAttack(time_t current_time) { return false; }
Mindmaster::Mindmaster(const MindmasterModel *model, time_t current_time,
                       Coordinate position)
    : Enemy(model->MAX_HEALTH, current_time, position), model_(model) {}
