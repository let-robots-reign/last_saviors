#include "event.h"

#include <utility>

IEvent::IEvent(EventType type) : type(type) {}

MouseClickEvent::MouseClickEvent(EventType type, const Coordinate &mouse) : IEvent(type), mouse(mouse) {}

TileEvent::TileEvent(EventType type, const Tile &selectedTile) : IEvent(type), selectedTile(selectedTile) {}

TowerEvent::TowerEvent(EventType type, Tower *tower) : IEvent(type), tower(tower) {}

PuzzleEvent::PuzzleEvent(EventType type, Puzzle chosenPuzzle) : IEvent(type), chosenPuzzle(std::move(chosenPuzzle)) {}

PuzzleAnswerEvent::PuzzleAnswerEvent(EventType type, bool answerCorrectness) : IEvent(type),
                                                                               answerCorrectness(answerCorrectness) {}

EnemyEvent::EnemyEvent(EventType type, Enemy *enemy) : IEvent(type), enemy(enemy) {}

CitadelEvent::CitadelEvent(EventType type, const Citadel &citadel) : IEvent(type), citadel(citadel) {}

GameResultsEvent::GameResultsEvent(EventType type, bool success, const Citadel &citadel, const IWave &waveInfo)
        : IEvent(type), success(success), citadel(citadel), waveInfo(waveInfo) {}

NoInfoEvent::NoInfoEvent(EventType type) : IEvent(type) {}

