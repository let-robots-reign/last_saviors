#ifndef CLIENT_LOADER_MANAGER_H
#define CLIENT_LOADER_MANAGER_H

#include "manager.h"
#include "event/event_emitter.h"
#include "loader.h"

template<typename T>
class LoaderManager : public Manager, public EventEmitter {
public:
    explicit LoaderManager(Loader<T> l);

    LoadingResult load();

    int processEvent(const Event &pevent) override;

    Event produceEvent() override;

private:
    // TODO: same template question
    Loader<T> loader;
    Event event;
};

#endif //CLIENT_LOADER_MANAGER_H
