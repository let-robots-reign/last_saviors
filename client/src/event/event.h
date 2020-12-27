#ifndef LAST_SAVIORS_EVENT_H
#define LAST_SAVIORS_EVENT_H

#include <list>
#include <algorithm>
#include <shared_mutex>
#include "event_handler.h"


template<typename ...TParams>
class IEvent {
protected:
    using EventHandler = AbstractEventHandler<TParams...>;

    IEvent() = default;

    virtual bool addHandler(EventHandler &eventHandler) = 0;

    virtual bool removeHandler(EventHandler &eventHandler) = 0;

public:
    // подписка на событие
    template<typename THandler>
    inline bool operator+=(THandler &&handler) {
        return addHandler(static_cast<EventHandler &>(handler));
    }

    // отписка от события
    template<typename THandler>
    inline bool operator-=(THandler &&handler) {
        return removeHandler(static_cast<EventHandler &>(handler));
    }
};


template<typename ...TParams>
class TEvent : public IEvent<TParams...> {
    using EventHandler = typename IEvent<TParams...>::EventHandler;
    using EventHandlerIt = typename std::list<EventHandler *>::const_iterator;
public:
    TEvent() : IEvent<TParams...>(), handlers(), currentIt(), isCurrentItRemoved(), handlerListMutex() {}

    ~TEvent() {
        for (EventHandler *handler : handlers) {
            delete handler;
        }
        handlers.clear();
    }

    void operator()(TParams... params) {
        handlerListMutex.lock_shared();

        isCurrentItRemoved = false;
        currentIt = handlers.begin();
        while (currentIt != handlers.end()) {
            handlerListMutex.unlock_shared();
            (*currentIt)->call(params...);
            handlerListMutex.lock_shared();

            if (isCurrentItRemoved) {
                isCurrentItRemoved = false;

                EventHandlerIt itToRemove = currentIt;
                deleteHandler(itToRemove);
            }
            ++currentIt;
        }

        handlerListMutex.unlock_shared();
    }

protected:

    bool addHandler(EventHandler &eventHandler) override {
        std::unique_lock<std::shared_mutex> handlerListMutexLock(handlerListMutex);

        if (findEventHandler(eventHandler) == handlers.end()) {
            handlers.push_back(&eventHandler);
            return true;
        }
        return false;
    }

    bool removeHandler(EventHandler &eventHandler) override {
        std::unique_lock<std::shared_mutex> handlerListMutexLock(handlerListMutex);

        auto it = findEventHandler(eventHandler);
        if (it != handlers.end()) {
            if (it == currentIt) {
                isCurrentItRemoved = true;
            } else {
                deleteHandler(it);
            }
            return true;
        }
        return false;
    }

private:
    std::list<EventHandler *> handlers;

    mutable EventHandlerIt currentIt;
    mutable bool isCurrentItRemoved;  // для корректной обработки самоотписки от события
    mutable std::shared_mutex handlerListMutex;

    inline EventHandlerIt findEventHandler(const EventHandler &handler) const {
        return std::find_if(handlers.cbegin(), handlers.cend(), [&handler](const EventHandler *rhs) {
            return (*rhs == handler);
        });
    }

    inline void deleteHandler(EventHandlerIt it) {
        EventHandler *handlerToRemove = *it;
        handlers.erase(it);
        delete handlerToRemove;
    }
};

#endif //LAST_SAVIORS_EVENT_H
