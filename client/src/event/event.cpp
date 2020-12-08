#include "event.h"

#include <utility>

template<typename... TParams>
IEvent<TParams...>::IEvent() = default;


template<typename... TParams>
bool IEvent<TParams...>::operator+=(IEvent::EventHandler &eventHandler) {
    return addHandler(eventHandler);
}

template<typename... TParams>
bool IEvent<TParams...>::operator-=(IEvent::EventHandler &eventHandler) {
    return removeHandler(eventHandler);
}

template<typename ...TParams>
TEvent<TParams...>::TEvent() : IEvent<TParams...>(), handlers(), currentIt(), isCurrentItRemoved(), handlerListMutex() {}

template<typename ...TParams>
TEvent<TParams...>::~TEvent() {
    for (EventHandler *handler : handlers) {
        delete handler;
    }
    handlers.clear();
}

template<typename ...TParams>
void TEvent<TParams...>::operator()(TParams... params) {
    handlerListMutex.lock_shared();

    isCurrentItRemoved = false;
    currentIt = handlers.begin();
    while (currentIt != handlers.end()) {
        handlerListMutex.unlock_shared();
        *currentIt->call(params...);
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

template<typename ...TParams>
bool TEvent<TParams...>::addHandler(const EventHandler &eventHandler) {
    std::unique_lock<std::shared_mutex> handlerListMutexLock(handlerListMutex);

    if (findEventHandler(eventHandler) == handlers.end()) {
        handlers.push_back(std::move(eventHandler));
        return true;
    }
    return false;
}

template<typename... TParams>
bool TEvent<TParams...>::removeHandler(const EventHandler &eventHandler) {
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


//TEvent::TEvent(EventType type) : type(type) {}
//
//MouseClickEvent::MouseClickEvent(EventType type, const Coordinate &mouse) : TEvent(type), mouse(mouse) {}
//
//TileEvent::TileEvent(EventType type, const Tile &selectedTile) : TEvent(type), selectedTile(selectedTile) {}
//
//TowerEvent::TowerEvent(EventType type, Tower *tower) : TEvent(type), tower(tower) {}
//
//PuzzleEvent::PuzzleEvent(EventType type, Puzzle chosenPuzzle) : TEvent(type), chosenPuzzle(std::move(chosenPuzzle)) {}
//
//PuzzleAnswerEvent::PuzzleAnswerEvent(EventType type, bool answerCorrectness) : TEvent(type),
//                                                                               answerCorrectness(answerCorrectness) {}
//
//EnemyEvent::EnemyEvent(EventType type, Enemy *enemy) : TEvent(type), enemy(enemy) {}
//
//CitadelEvent::CitadelEvent(EventType type, const Citadel &citadel) : TEvent(type), citadel(citadel) {}
//
//GameResultsEvent::GameResultsEvent(EventType type, bool success, const Citadel &citadel, const IWave &waveInfo)
//        : TEvent(type), success(success), citadel(citadel), waveInfo(waveInfo) {}
//
//NoInfoEvent::NoInfoEvent(EventType type) : TEvent(type) {}
//
