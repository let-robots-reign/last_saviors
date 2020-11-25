#ifndef DATABASE_QQUESTMAPPER_H
#define DATABASE_QQUESTMAPPER_H

#include "IQQuestMapper.h"

class QQuestMapper : IQQuestMapper{
public:
    QuizQuestion getRandQuizQuestion() override;
};


#endif //DATABASE_QQUESTMAPPER_H
