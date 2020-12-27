#ifndef DATABASE_PROGQUESTION_H
#define DATABASE_PROGQUESTION_H

#include "puzzle.h"
#include <string>

class ProgPuzzle : public Puzzle {
public:
    ProgPuzzle(size_t id, const std::string &question, std::string answer);

private:
    std::string answer;
};


#endif //DATABASE_PROGQUESTION_H
