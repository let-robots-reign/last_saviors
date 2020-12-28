#include "attackable.h"


void Attackable::reduceHealth(unsigned int value) {
    if (health_ <= value) {
        is_alive = false;
    } else {
        health_ -= value;
    }
}
void Attackable::setHealth(unsigned int value) {
    if (value == 0) throw std::invalid_argument("Zero health");
    health_ = value;
}
Attackable::Attackable(unsigned int health, Coordinate position)
    : Unit(position), is_alive(true) {
    setHealth(health);
}
