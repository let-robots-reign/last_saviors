#ifndef LAST_SAVIORS_PUZZLE_H
#define LAST_SAVIORS_PUZZLE_H

#include <cstddef>
#include <string>

class Puzzle {
protected:
    size_t id;
    std::string question;
    std::string answer;
    size_t puzzleComplexity;
};

#endif //LAST_SAVIORS_PUZZLE_H
