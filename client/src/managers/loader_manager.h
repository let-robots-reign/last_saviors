#ifndef CLIENT_LOADER_MANAGER_H
#define CLIENT_LOADER_MANAGER_H

#include "manager.h"
#include "event_emitter.h"
#include "loader.h"

class LoaderManager : public Manager, public EventEmitter {
public:
    explicit LoaderManager(const Loader & l);

    LoadingResult load();

    int processEvent(const IEvent &pevent) override;

    IEvent *produceEvent() override;

private:
    Loader loader;
};

#endif //CLIENT_LOADER_MANAGER_H
