#include "my_sql.h"

MySQL::MySQL() {

}

bool MySQL::sign_in(User user) {
    return false;
}

bool MySQL::sign_up(User user) {
    return false;
}

UserScore MySQL::getUserScore(int userId) {
    return UserScore();
}

std::vector<UserScore> MySQL::getTopNScore(int N) {
    return std::vector<UserScore>();
}

QuizQuestion MySQL::getRandQuizQuestion() {
    return QuizQuestion();
}

ProgQuestion MySQL::getRandProgQuestion() {
    return ProgQuestion();
}
