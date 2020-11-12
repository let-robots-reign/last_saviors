#ifndef DATABASE_GAMEDB_H
#define DATABASE_GAMEDB_H


#include <memory>
#include <vector>
#include "DBMS.h"
#include "../Data/UserScore.h"
#include "../Data/User.h"
#include "../Data/QuizQuestion.h"
#include "../Data/ProgQuestion.h"

class GameDB {
private:
//    GameDB(DBMS database);
public:
//    static GameDB getInstance(DBMS database);

    bool sign_in(User user);
    bool sign_up(User user);

    UserScore getUserScore(int userId);
    std::vector<UserScore> getTopNScore(int N);

    QuizQuestion getRandQuizQuestion();
    ProgQuestion getRandProgQuestion();

private:
    std::unique_ptr<GameDB> db = nullptr;
    std::unique_ptr<DBMS> dbms = nullptr;
};


#endif //DATABASE_GAMEDB_H
