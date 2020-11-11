#include "user_input.h"

UserInput::UserInput(GameState context) : currentGameState(context) {}

char UserInput::getPressedKey() {
    return 0;
}

Coordinate UserInput::getMouseCoords() {
    return Coordinate();
}
