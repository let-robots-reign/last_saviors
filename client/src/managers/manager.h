#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include "event.h"

class Manager {
public:
    virtual int processEvent(const IEvent &event) = 0;
};

#endif //CLIENT_MANAGER_H
