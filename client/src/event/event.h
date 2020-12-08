#ifndef LAST_SAVIORS_EVENT_H
#define LAST_SAVIORS_EVENT_H

#include <list>
#include <shared_mutex>
#include "event_handler.h"


template<typename ...TParams>
class IEvent {
protected:
    using EventHandler = AbstractEventHandler<TParams...>;

    IEvent();

    virtual bool addHandler(EventHandler &eventHandler) = 0;

    virtual bool removeHandler(EventHandler &eventHandler) = 0;

public:
    // подписка на событие
    bool operator+=(EventHandler &eventHandler);

    // отписка от события
    bool operator-=(EventHandler &eventHandler);
};


template<typename ...TParams>
class TEvent : public IEvent<TParams...> {
    using EventHandler = typename IEvent<TParams...>::EventHandler;
    using EventHandlerIt = typename std::list<EventHandler *>::const_iterator;
public:
    TEvent();

    ~TEvent();

protected:
    void operator()(TParams... params);

    bool addHandler(EventHandler &eventHandler) override;

    bool removeHandler(EventHandler &eventHandler) override;

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


//enum EventType {
//    MouseClicked,
//    StartSingleMatch,
//    StartMultiplayerMatch,
//    EverythingLoaded,
//    WaveStarted,
//    WaveFinished,
//    TilePressed,
//    TowerMenuOpened,
//    PuzzleOpened,
//    PuzzleAnswered,
//    TowerPlaced,
//    TowerAttacked,
//    TowerDestroyed,
//    TowerBroken,
//    TowerRepaired,
//    CitadelAttacked,
//    EnemyHitted,
//    EnemyKilled,
//    GameFinished,
//    EmptyEvent
//};
//
//class TEvent {
//public:
//    explicit TEvent(EventType type);
//
//    const EventType &getEventType() const {
//        return type;
//    }
//
//private:
//    EventType type;
//};
//
//class MouseClickEvent : public TEvent {
//public:
//    MouseClickEvent(EventType type, const Coordinate &mouse);
//
//    inline const Coordinate &getMouse() const {
//        return mouse;
//    }
//
//private:
//    Coordinate mouse;
//};
//
//class TileEvent : public TEvent {
//public:
//    TileEvent(EventType type, const Tile &selectedTile);
//
//    inline const Tile &getSelectedTile() const {
//        return selectedTile;
//    }
//
//private:
//    Tile selectedTile;
//};
//
//class TowerEvent : public TEvent {
//public:
//    TowerEvent(EventType type, Tower *tower);
//
//    inline const Tower *getTower() const {
//        return tower;
//    }
//
//private:
//    Tower *tower;
//};
//
//class PuzzleEvent : public TEvent {
//public:
//    PuzzleEvent(EventType type, Puzzle chosenPuzzle);
//
//    inline const Puzzle &getPuzzle() const {
//        return chosenPuzzle;
//    }
//
//private:
//    Puzzle chosenPuzzle;
//};
//
//class PuzzleAnswerEvent : public TEvent {
//public:
//    PuzzleAnswerEvent(EventType type, bool answerCorrectness);
//
//    inline const bool &getAnswerCorrectness() const {
//        return answerCorrectness;
//    }
//
//private:
//    bool answerCorrectness;
//};
//
//class EnemyEvent : public TEvent {
//public:
//    EnemyEvent(EventType type, Enemy *enemy);
//
//    inline const Enemy *getEnemy() const {
//        return enemy;
//    };
//private:
//    Enemy *enemy;
//};
//
//class CitadelEvent : public TEvent {
//public:
//    CitadelEvent(EventType type, const Citadel &citadel);
//
//    inline const Citadel &getCitadel() const {
//        return citadel;
//    }
//
//private:
//    Citadel citadel;
//};
//
//class GameResultsEvent : public TEvent {
//public:
//    GameResultsEvent(EventType type, bool success, const Citadel &citadel, const IWave &waveInfo);
//
//    inline const bool &getSuccess() const {
//        return success;
//    }
//
//    inline const Citadel &getCitadel() const {
//        return citadel;
//    }
//
//    inline const IWave &getWave() const {
//        return waveInfo;
//    }
//
//private:
//    bool success;
//    Citadel citadel;
//    IWave waveInfo;
//};
//
//class NoInfoEvent : public TEvent {
//public:
//    explicit NoInfoEvent(EventType type);
//};
//
//
#endif //LAST_SAVIORS_EVENT_H
