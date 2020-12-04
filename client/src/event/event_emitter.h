#ifndef LAST_SAVIORS_EVENT_EMITTER_H
#define LAST_SAVIORS_EVENT_EMITTER_H

#include "event.h"

class EventEmitter {
public:
    virtual IEvent *produceEvent() = 0;
};

#endif //LAST_SAVIORS_EVENT_EMITTER_H
