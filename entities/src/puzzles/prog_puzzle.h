#ifndef DATABASE_PROGQUESTION_H
#define DATABASE_PROGQUESTION_H

#include "puzzle.h"
#include <string>

class ProgPuzzle : public Puzzle {
private:
    std::string answer;
public:
    ProgPuzzle(size_t id, const std::string &question, size_t puzzleComplexity, const std::string &answer);
};


#endif //DATABASE_PROGQUESTION_H
