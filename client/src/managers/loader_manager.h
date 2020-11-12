#ifndef CLIENT_LOADER_MANAGER_H
#define CLIENT_LOADER_MANAGER_H

#include "manager.h"
#include "event/event_emitter.h"
#include "loader.h"

class LoaderManager : public Manager, public EventEmitter {
public:
    explicit LoaderManager(Loader l);

    LoadingResult load();

    int processEvent(const Event &pevent) override;

    Event produceEvent() override;



private:
    Loader loader;
    Event event;
};

#endif //CLIENT_LOADER_MANAGER_H
