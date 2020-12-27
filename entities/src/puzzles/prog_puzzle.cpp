#include "prog_puzzle.h"

ProgPuzzle::ProgPuzzle(size_t id, const std::string &question, std::string answer)
        : Puzzle(id, question), answer(std::move(answer)) {}
