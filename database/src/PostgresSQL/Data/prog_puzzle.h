#ifndef DATABASE_PROGQUESTION_H
#define DATABASE_PROGQUESTION_H


#include <string>

class ProgPuzzle {
public:
    int id;
    std::string question;
    std::string answer;
    int questionComplexity;

};


#endif //DATABASE_PROGQUESTION_H
