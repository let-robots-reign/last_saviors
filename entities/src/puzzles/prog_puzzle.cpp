#include "prog_puzzle.h"

ProgPuzzle::ProgPuzzle(size_t id, const std::string &question, size_t puzzleComplexity, const std::string &answer)
        : Puzzle(id, question, puzzleComplexity), answer(answer) {}
