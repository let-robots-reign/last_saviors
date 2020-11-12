#include "pawn.h"

Pawn::Pawn(const PawnModel *model, Coordinate position)
    : Enemy(model->MAX_HEALTH, position), model_(model) {}
void Pawn::atDeath(Player *player) {
    }
void Pawn::attack(AttackableBuilding *building) {
    }
bool Pawn::canAttack() {
    return true;
}