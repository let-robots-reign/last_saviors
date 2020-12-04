#ifndef LAST_SAVIORS_EVENT_H
#define LAST_SAVIORS_EVENT_H

#include <variant>

#include "tower.h"
#include "puzzle.h"
#include "enemy.h"
#include "citadel.h"
#include "wave.h"
#include "coordinate.h"
#include "tile.h"


enum EventType {
    MouseClicked,
    StartSingleMatch,
    StartMultiplayerMatch,
    EverythingLoaded,
    WaveStarted,
    WaveFinished,
    TilePressed,
    TowerMenuOpened,
    PuzzleOpened,
    PuzzleAnswered,
    TowerPlaced,
    TowerAttacked,
    TowerDestroyed,
    TowerBroken,
    TowerRepaired,
    CitadelAttacked,
    EnemyHitted,
    EnemyKilled,
    GameFinished,
    EmptyEvent
};

class IEvent {
public:
    explicit IEvent(EventType type);

    const EventType &getEventType() const {
        return type;
    }

private:
    EventType type;
};

class MouseClickEvent : public IEvent {
public:
    MouseClickEvent(EventType type, const Coordinate &mouse);

    inline const Coordinate &getMouse() const {
        return mouse;
    }

private:
    Coordinate mouse;
};

class TileEvent : public IEvent {
public:
    TileEvent(EventType type, const Tile &selectedTile);

    inline const Tile &getSelectedTile() const {
        return selectedTile;
    }

private:
    Tile selectedTile;
};

class TowerEvent : public IEvent {
public:
    TowerEvent(EventType type, Tower *tower);

    inline const Tower *getTower() const {
        return tower;
    }

private:
    Tower *tower;
};

class PuzzleEvent : public IEvent {
public:
    PuzzleEvent(EventType type, Puzzle chosenPuzzle);

    inline const Puzzle &getPuzzle() const {
        return chosenPuzzle;
    }

private:
    Puzzle chosenPuzzle;
};

class PuzzleAnswerEvent : public IEvent {
public:
    PuzzleAnswerEvent(EventType type, bool answerCorrectness);

    inline const bool &getAnswerCorrectness() const {
        return answerCorrectness;
    }

private:
    bool answerCorrectness;
};

class EnemyEvent : public IEvent {
public:
    EnemyEvent(EventType type, Enemy *enemy);

    inline const Enemy *getEnemy() const {
        return enemy;
    };
private:
    Enemy *enemy;
};

class CitadelEvent : public IEvent {
public:
    CitadelEvent(EventType type, const Citadel &citadel);

    inline const Citadel &getCitadel() const {
        return citadel;
    }

private:
    Citadel citadel;
};

class GameResultsEvent : public IEvent {
public:
    GameResultsEvent(EventType type, bool success, const Citadel &citadel, const IWave &waveInfo);

    inline const bool &getSuccess() const {
        return success;
    }

    inline const Citadel &getCitadel() const {
        return citadel;
    }

    inline const IWave &getWave() const {
        return waveInfo;
    }

private:
    bool success;
    Citadel citadel;
    IWave waveInfo;
};

class NoInfoEvent : public IEvent {
public:
    explicit NoInfoEvent(EventType type);
};


#endif //LAST_SAVIORS_EVENT_H
