#include "mindmaster.h"

Mindmaster::Mindmaster(const MindmasterModel *model, Coordinate position)
    : Enemy(model->MAX_HEALTH, position), model_(model) {}

bool Mindmaster::canAttack() { return true; }
void Mindmaster::attack(AttackableBuilding *building) { return; }
void Mindmaster::atDeath(Player *player) { return; }
