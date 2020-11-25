#include "enemy.h"

Enemy::Enemy(int health, Coordinate position)
    : Unit(position), health_(health), timeOfLastAttack_(0) {}
void Enemy::reduceHealth(AttackableBuilding *building) { }
