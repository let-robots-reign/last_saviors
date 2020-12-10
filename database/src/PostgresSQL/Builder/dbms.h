#ifndef DATABASE_DBMS_H
#define DATABASE_DBMS_H

#include <vector>
#include "user.h"
#include "user_score.h"
#include "quiz_puzzlez.h"
#include "prog_puzzle.h"

class DBMS {
public:
    DBMS() = default;;

    virtual bool sign_in(User user) = 0;

    virtual bool sign_up(User user) = 0;

    virtual UserScore getUserScore(int userId) = 0;

    virtual std::vector<UserScore> getTopNScore(int N) = 0;

    virtual QuizPuzzle getRandQuizPuzzle() = 0;

    virtual ProgPuzzle getRandProgPuzzle() = 0;
};


#endif //DATABASE_DBMS_H
