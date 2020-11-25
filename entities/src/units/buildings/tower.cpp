#include "tower.h"

Tower::Tower(int health, Coordinate position, int level)
    : AttackableBuilding(health, position),
      timeOfLastAttack_(0),
      level_(level) {}
void Tower::upgrade(Player *player) {}