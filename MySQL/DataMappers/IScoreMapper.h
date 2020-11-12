#ifndef DATABASE_ISCOREMAPPER_H
#define DATABASE_ISCOREMAPPER_H


#include <vector>
#include "../Data/UserScore.h"

class IScoreMapper {
    virtual UserScore getUserScore(int userId) = 0;
    virtual std::vector<UserScore> getTopNScore(int N) = 0;
};


#endif //DATABASE_ISCOREMAPPER_H
