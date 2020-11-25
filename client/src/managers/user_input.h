#ifndef CLIENT_USER_INPUT_H
#define CLIENT_USER_INPUT_H

#include "game_state.h"
#include "coordinate.h"


class UserInput {
public:
    explicit UserInput(GameState context);

    char getPressedKey() const;

    Coordinate getMouseCoords() const;

private:
    GameState currentGameState;
};

#endif //CLIENT_USER_INPUT_H
