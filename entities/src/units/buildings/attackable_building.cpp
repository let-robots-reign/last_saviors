#include "attackable_building.h"

AttackableBuilding::AttackableBuilding(int health, Coordinate position)
    : Unit(position), health_(health) {}
void AttackableBuilding::reduceHealth(int value) { health_ -= value; }
void AttackableBuilding::setHeath(int value) { health_ = value; }