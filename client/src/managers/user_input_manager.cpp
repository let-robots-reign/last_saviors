#include "user_input_manager.h"

UserInputManager::UserInputManager(UserInput input) : userInput(input) {}

int UserInputManager::processEvent(const Event &pevent) {
    return 0;
}

Event UserInputManager::produceEvent() {
    event.type = MouseClicked;
    event.info = MouseClickInfo();
    return event;
}
