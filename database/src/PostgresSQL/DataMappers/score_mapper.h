#ifndef DATABASE_SCOREMAPPER_H
#define DATABASE_SCOREMAPPER_H


#include <memory>
#include "iscore_mapper.h"
#include "idb_conn.h"


class ScoreMapper : public IScoreMapper {
public:
    explicit ScoreMapper(std::shared_ptr<IDBConn> &new_dbConn);

    UserScore getUserScore(int userId) override;

    std::vector<UserScore> getTopNScore(int N) override;
};


#endif //DATABASE_SCOREMAPPER_H
