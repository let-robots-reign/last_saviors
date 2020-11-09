#ifndef LAST_SAVIORS_EVENT_H
#define LAST_SAVIORS_EVENT_H

#include "coordinate.h"

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

union EventInfo {
    TileInfo tileInfo;
    TowerInfo towerInfo;
    PuzzleInfo puzzleInfo;
    PuzzleAnswerInfo answerInfo;
    EnemyInfo enemyInfo;
    CitadelInfo citadelInfo;
    GameResultsInfo gameResultsInfo;
    NoInfoEvent noInfo;
};

class Event {
public:
    Event(EventType ptype, EventInfo pinfo) : type(ptype), info(pinfo) {}
private:
    EventType type;
    EventInfo info;
};

#endif //LAST_SAVIORS_EVENT_H
