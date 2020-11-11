#ifndef CLIENT_USER_INPUT_MANAGER_H
#define CLIENT_USER_INPUT_MANAGER_H

#include "manager.h"
#include "event/event_emitter.h"
#include "user_input.h"

class UserInputManager : public Manager, public EventEmitter {
public:
    explicit UserInputManager(UserInput input);

    int processEvent(const Event &pevent) override;

    Event produceEvent() override;
private:
    UserInput userInput;
    Event event;
};

#endif //CLIENT_USER_INPUT_MANAGER_H
