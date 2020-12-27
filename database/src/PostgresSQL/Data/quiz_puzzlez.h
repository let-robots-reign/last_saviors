#ifndef DATABASE_QUIZQUESTION_H
#define DATABASE_QUIZQUESTION_H


#include <string>
#include <vector>


class QuizPuzzle {
public:
    int id;
    std::string question;
    std::string answer1;
    std::string answer2;
    std::string answer3;
    std::string answer4;
    int correctAnswer;
    int questionComplexity;
};


#endif //DATABASE_QUIZQUESTION_H
