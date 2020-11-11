#ifndef LAST_SAVIORS_EVENT_H
#define LAST_SAVIORS_EVENT_H

#include <variant>
#include "entities/coordinate.h"

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
    GameFinished
};

struct MouseClickInfo {
    Coordinate mouse;
};

struct TileInfo {
    Tile selectedTile;
};

struct TowerInfo {
    Tower tower;
};

struct PuzzleInfo {
    Puzzle chosenPuzzle;
};

struct PuzzleAnswerInfo {
    bool answerCorrectness;
};

struct EnemyInfo {
    Enemy enemy;
};

struct CitadelInfo {
    Citadel citadel;
};

struct GameResultsInfo {
    bool success;
    Citadel citadel;
    Wave waveInfo;
};

struct NoInfoEvent {

};

using EventInfo = std::variant<MouseClickInfo, TileInfo, TowerInfo, PuzzleInfo, PuzzleAnswerInfo, EnemyInfo, CitadelInfo, GameResultsInfo, NoInfoEvent>;

class Event {
public:
    Event(EventType ptype, EventInfo pinfo);

private:
    EventType type;
    EventInfo info;
};

#endif //LAST_SAVIORS_EVENT_H
