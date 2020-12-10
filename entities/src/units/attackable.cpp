#include "attackable.h"


void Attackable::reduceHealth(unsigned int value) {
    if (health_ <= value) {
        atDeath();
    } else {
        health_ -= value;
    }
}
void Attackable::setHealth(unsigned int value) {
    if (value == 0) throw std::invalid_argument("Zero health");
    health_ = value;
}
Attackable::Attackable(unsigned int health, Coordinate position)
    : Unit(position) {
    try {
        setHealth(health);
    } catch (...) {
        throw;
    }
}
