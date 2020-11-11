#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include "event/event.h"

class Manager {
public:
    virtual int processEvent(const Event &event) = 0;
};

#endif //CLIENT_MANAGER_H
