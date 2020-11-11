#include "user_input_manager.h"

UserInputManager::UserInputManager(UserInput input) : userInput(input), event(Event()) {}

int UserInputManager::processEvent(const Event &pevent) {
    return 0;
}

Event UserInputManager::produceEvent() {
    event.setType(EmptyEvent);
    event.setInfo(NoInfoEvent());
    return event;
}
