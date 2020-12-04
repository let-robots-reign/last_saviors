#include "user_input_manager.h"

UserInputManager::UserInputManager(const UserInput &userInput) : userInput(userInput) {}

int UserInputManager::processEvent(const IEvent &pevent) {
    return 0;
}

IEvent *UserInputManager::produceEvent() {
    Coordinate mouseCoordinate;
    return new MouseClickEvent(MouseClicked, mouseCoordinate);
}
