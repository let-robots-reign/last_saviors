#ifndef CLIENT_USER_INPUT_MANAGER_H
#define CLIENT_USER_INPUT_MANAGER_H

#include "manager.h"
#include "event_emitter.h"
#include "user_input.h"

class UserInputManager : public Manager, public EventEmitter {
public:
    explicit UserInputManager(const UserInput &userInput);

    int processEvent(const IEvent &pevent) override;

    IEvent *produceEvent() override;

private:
    UserInput userInput;
};

#endif //CLIENT_USER_INPUT_MANAGER_H
