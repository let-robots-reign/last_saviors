#include "event.h"

#include <utility>

template<typename ...TParams>
TEvent<TParams...>::TEvent() : handlers() {}

template<typename ...TParams>
TEvent<TParams...>::~TEvent() {
    for (EventHandler *handler : handlers) {
        delete handler;
    }
    handlers.clear();
}

template<typename ...TParams>
void TEvent<TParams...>::operator()(TParams... params) {
    for (const EventHandler &handler : handlers) {
        handler.call(params...);
    }
}

template<typename ...TParams>
bool TEvent<TParams...>::operator+=(const TEvent::EventHandler &eventHandler) {
    if (findEventHandler(eventHandler) == handlers.end()) {
        handlers.push_back(&eventHandler);
        return true;
    }
    return false;
}

template<typename... TParams>
bool TEvent<TParams...>::operator-=(const TEvent::EventHandler &eventHandler) {
    auto it = findEventHandler(eventHandler);
    if (it != handlers.end()) {
        EventHandler *handlerToRemove = *it;
        handlers.erase(handlerToRemove);
        delete handlerToRemove;
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
