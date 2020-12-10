#ifndef DATABASE_GAMEDB_H
#define DATABASE_GAMEDB_H

#include <memory>
#include <vector>
#include "dbms.h"
#include "user_score.h"
#include "user.h"
#include "quiz_puzzlez.h"
#include "prog_puzzle.h"

class GameDB {
private:
//    GameDB(DBMS database);
public:
//    static GameDB getInstance(DBMS database);

    bool sign_in(User user);

    bool sign_up(User user);

    UserScore getUserScore(int userId);

    std::vector<UserScore> getTopNScore(int N);

    QuizPuzzle getRandQuizPuzzle();

    ProgPuzzle getRandProgPuzzle();

private:
    std::unique_ptr<GameDB> db = nullptr;
    std::unique_ptr<DBMS> dbms = nullptr;
};


#endif //DATABASE_GAMEDB_H
