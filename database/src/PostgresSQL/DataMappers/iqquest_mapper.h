#ifndef DATABASE_IQQUESTMAPPER_H
#define DATABASE_IQQUESTMAPPER_H

#include "quiz_puzzlez.h"

class IQQuestMapper {
public:
    virtual QuizPuzzle getRandQuizPuzzle() = 0;
};


#endif //DATABASE_IQQUESTMAPPER_H
