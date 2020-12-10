#ifndef DATABASE_SCOREMAPPER_H
#define DATABASE_SCOREMAPPER_H

#include <memory>
#include "iscore_mapper.h"
#include "idb_conn.h"

class ScoreMapper : public IScoreMapper {
public:
    UserScore getUserScore(int userId) override;

    std::vector<UserScore> getTopNScore(int N) override;

private:
    std::shared_ptr<IDBConn> dbConn = nullptr;
};


#endif //DATABASE_SCOREMAPPER_H