#include "user_input.h"

UserInput::UserInput(GameState context) : currentGameState(context) {}

char UserInput::getPressedKey() const {
    return 0;
}

Coordinate UserInput::getMouseCoords() const {
    return Coordinate();
}
