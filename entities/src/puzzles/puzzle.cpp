#include "puzzle.h"

#include <utility>

Puzzle::Puzzle(size_t id, std::string question, size_t puzzleComplexity) : id(id), question(std::move(question)),
                                                                                  puzzleComplexity(puzzleComplexity) {}
