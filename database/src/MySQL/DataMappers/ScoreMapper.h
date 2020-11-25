#ifndef DATABASE_SCOREMAPPER_H
#define DATABASE_SCOREMAPPER_H

#include <memory>
#include "IScoreMapper.h"
#include "IDBConn.h"

class ScoreMapper : public IScoreMapper {
public:
    UserScore getUserScore(int userId) override;

    std::vector<UserScore> getTopNScore(int N) override;

private:
    std::shared_ptr<IDBConn> dbConn = nullptr;
};


#endif //DATABASE_SCOREMAPPER_H
