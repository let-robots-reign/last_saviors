#include "score_mapper.h"


ScoreMapper::ScoreMapper(std::shared_ptr<IDBConn> &new_dbConn) {
    this->dbConn = new_dbConn;
}

UserScore ScoreMapper::getUserScore(int userId) {
    dbConn->DBExec("select * from leaderboard where user_id=\'" + std::to_string(userId) + "\';");
    if (dbConn->getDBTuples() != 0) {
        UserScore user_score;
        user_score.userId = userId;
        user_score.score = std::stoi(dbConn->DBGetValue(0, 1));

        return user_score;
    }

    // TODO: Сделать исключения
}

std::vector<UserScore> ScoreMapper::getTopNScore(int N) {
    dbConn->DBExec("select * from leaderboard ORDER BY score LIMIT " + std::to_string(N) + ";");

    std::vector<UserScore> topScores;

    if (dbConn->getDBTuples() != 0) {
        for (int i = 0; i < dbConn->getDBTuples(); i++) {
            UserScore user_score;
            user_score.userId = std::stoi(dbConn->DBGetValue(i, 0));;
            user_score.score = std::stoi(dbConn->DBGetValue(i, 1));

            topScores.push_back(user_score);
        }
    }

    return topScores;
}
