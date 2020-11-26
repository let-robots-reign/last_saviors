#include "game_db.h"

//GameDB::GameDB(DBMS database) {
//
//}
//
//GameDB GameDB::getInstance(DBMS database) {
//    return GameDB(DBMS());
//}

bool GameDB::sign_in(User user) {
    return false;
}

bool GameDB::sign_up(User user) {
    return false;
}

UserScore GameDB::getUserScore(int userId) {
    return UserScore();
}

std::vector<UserScore> GameDB::getTopNScore(int N) {
    return std::vector<UserScore>();
}

QuizQuestion GameDB::getRandQuizQuestion() {
    return QuizQuestion();
}

ProgQuestion GameDB::getRandProgQuestion() {
    return ProgQuestion();
}
