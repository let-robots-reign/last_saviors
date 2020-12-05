#include "attackable.h"

void Attackable::reduceHealth(int value) {
    health_ -= value;
    if (health_ <= 0) {
        onFinish();
    }
}
void Attackable::setHealth(int value) {
    if (value <= 0) return;
    health_ = value;
}
Attackable::Attackable(int health, Coordinate position)
    : Unit(position), health_(health) {}
