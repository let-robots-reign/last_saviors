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

struct MouseClickInfo {
    Coordinate mouse;
};

struct TileInfo {
    Tile selectedTile;
};

struct TowerInfo {
    Tower *tower;
};

struct PuzzleInfo {
    Puzzle chosenPuzzle;
};

struct PuzzleAnswerInfo {
    bool answerCorrectness;
};

struct EnemyInfo {
    Enemy *enemy;
};

struct CitadelInfo {
    Citadel citadel;
};

struct GameResultsInfo {
    bool success;
    Citadel citadel;
    IWave waveInfo;
};

struct NoInfoEvent {

};

// TODO: remove std::variant
using EventInfo = std::variant<MouseClickInfo, TileInfo, TowerInfo, PuzzleInfo, PuzzleAnswerInfo, EnemyInfo, CitadelInfo, GameResultsInfo, NoInfoEvent>;
//using EventInfo = std::variant<NoInfoEvent>;

class Event {
public:
    Event();

    Event(EventType ptype, EventInfo pinfo);

    void setType(EventType type);

    void setInfo(const EventInfo &info);

private:
    EventType type;
    EventInfo info;
};

#endif //LAST_SAVIORS_EVENT_H
