#ifndef CLIENT_USER_INPUT_H
#define CLIENT_USER_INPUT_H

#include "coordinate.h"

enum GameState {
    MainMenu,
    InGame,
    InTowersMenu,
    InPuzzle,
    GameOver
};

class UserInput {
public:
    UserInput(GameState context) : currentGameState(context) {}

    Coordinate getMouseCoords();

private:
    GameState currentGameState;
};

#endif //CLIENT_USER_INPUT_H
