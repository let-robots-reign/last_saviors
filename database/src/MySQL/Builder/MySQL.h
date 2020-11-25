#ifndef DATABASE_MYSQL_H
#define DATABASE_MYSQL_H

#include <memory>
#include "DBMS.h"
#include "ScoreMapper.h"
#include "QQuestMapper.h"
#include "UsersMapper.h"
#include "PQuestMapper.h"
#include "IDBConn.h"

class MySQL : public DBMS {
public:
    MySQL();

    bool sign_in(User user) override;

    bool sign_up(User user) override;

    UserScore getUserScore(int userId) override;

    std::vector<UserScore> getTopNScore(int N) override;

    QuizQuestion getRandQuizQuestion() override;

    ProgQuestion getRandProgQuestion() override;

private:
    std::shared_ptr<IDBConn> dbConn = nullptr;
    std::unique_ptr<UsersMapper> userM = nullptr;
    std::unique_ptr<ScoreMapper> scoreM = nullptr;
    std::unique_ptr<QQuestMapper> QQuestM = nullptr;
    std::unique_ptr<PQuestMapper> PQuestM = nullptr;

};


#endif //DATABASE_MYSQL_H
