#ifndef LAST_SAVIORS_PUZZLE_H
#define LAST_SAVIORS_PUZZLE_H

#include <cstddef>
#include <string>

class Puzzle {
private:
    size_t id;
    std::string question;
    size_t puzzleComplexity;
public:
    Puzzle(size_t id, std::string question, size_t puzzleComplexity);
};

#endif //LAST_SAVIORS_PUZZLE_H
