#include "shaft.h"

Shaft::Shaft(const ShaftModel *model, Coordinate position, int level)
    :Unit(position), timeOfLastUsage_(0),level_(level), model_(model) {}
bool Shaft::canGetCoins() {
    return true;
}
void Shaft::getCoins(Player *player) {}