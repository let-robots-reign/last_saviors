#ifndef DATABASE_IQQUESTMAPPER_H
#define DATABASE_IQQUESTMAPPER_H

#include "quiz_question.h"

class IQQuestMapper {
public:
    virtual QuizQuestion getRandQuizQuestion() = 0;
};


#endif //DATABASE_IQQUESTMAPPER_H
