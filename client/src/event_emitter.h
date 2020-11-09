#ifndef LAST_SAVIORS_EVENT_EMITTER_H
#define LAST_SAVIORS_EVENT_EMITTER_H

class EventEmitter {
public:
    virtual Event produceEvent() = 0;
};

#endif //LAST_SAVIORS_EVENT_EMITTER_H
