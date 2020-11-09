#ifndef CLIENT_LOADER_MANAGER_H
#define CLIENT_LOADER_MANAGER_H

#include "manager.h"
#include "event_emitter.h"
#include "loader.h"

template<typename T>
class LoaderManager : public Manager, public EventEmitter {
public:
    explicit LoaderManager(Loader<T> l) : loader(l) {}

    int processEvent(const Event &event) override;

    Event produceEvent() override;

private:
    // TODO: same template question
    Loader<T> loader;
};

#endif //CLIENT_LOADER_MANAGER_H
