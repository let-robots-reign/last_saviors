#ifndef DATABASE_IQQUESTMAPPER_H
#define DATABASE_IQQUESTMAPPER_H

#include <idb_conn.h>
#include "quiz_puzzlez.h"

class IQQuestMapper {
public:
    virtual QuizPuzzle getRandQuizPuzzle() = 0;

protected:
    std::shared_ptr<IDBConn> dbConn = nullptr;
};


#endif //DATABASE_IQQUESTMAPPER_H
