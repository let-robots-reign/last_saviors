#ifndef DATABASE_QQUESTMAPPER_H
#define DATABASE_QQUESTMAPPER_H


#include <memory>
#include "iqquest_mapper.h"


class QQuestMapper : public IQQuestMapper{
public:
    explicit QQuestMapper(std::shared_ptr<IDBConn> &new_dbConn);
    QuizPuzzle getRandQuizPuzzle() override;
};


#endif //DATABASE_QQUESTMAPPER_H
