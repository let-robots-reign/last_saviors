#ifndef DATABASE_ISCOREMAPPER_H
#define DATABASE_ISCOREMAPPER_H


#include <vector>
#include <idb_conn.h>
#include "user_score.h"


class IScoreMapper {
public:
    virtual UserScore getUserScore(int userId) = 0;

    virtual std::vector<UserScore> getTopNScore(int N) = 0;

protected:
    std::shared_ptr<IDBConn> dbConn = nullptr;
};


#endif //DATABASE_ISCOREMAPPER_H
