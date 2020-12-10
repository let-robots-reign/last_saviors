#include "pgsql.h"

pgsql::pgsql() {

}

bool pgsql::sign_in(User user) {
    return false;
}

bool pgsql::sign_up(User user) {
    return false;
}

UserScore pgsql::getUserScore(int userId) {
    return UserScore();
}

std::vector<UserScore> pgsql::getTopNScore(int N) {
    return std::vector<UserScore>();
}

QuizPuzzle pgsql::getRandQuizPuzzle() {
    return QuizPuzzle();
}

ProgPuzzle pgsql::getRandProgPuzzle() {
    return ProgPuzzle();
}
