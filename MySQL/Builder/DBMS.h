#ifndef DATABASE_DBMS_H
#define DATABASE_DBMS_H


#include <vector>
#include "../Data/User.h"
#include "../Data/UserScore.h"
#include "../Data/QuizQuestion.h"
#include "../Data/ProgQuestion.h"

class DBMS {
public:
    DBMS() = default;;
    virtual bool sign_in(User user) = 0;
    virtual bool sign_up(User user) = 0;

    virtual UserScore getUserScore(int userId) = 0;
    virtual std::vector<UserScore> getTopNScore(int N) = 0;

    virtual QuizQuestion getRandQuizQuestion() = 0;
    virtual ProgQuestion getRandProgQuestion() = 0;
};


#endif //DATABASE_DBMS_H
