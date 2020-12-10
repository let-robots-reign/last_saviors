#ifndef DATABASE_QQUESTMAPPER_H
#define DATABASE_QQUESTMAPPER_H

#include "iqquest_mapper.h"

class QQuestMapper : IQQuestMapper{
public:
    QuizPuzzle getRandQuizPuzzle() override;
};


#endif //DATABASE_QQUESTMAPPER_H
