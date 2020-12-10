#ifndef DATABASE_QUIZQUESTION_H
#define DATABASE_QUIZQUESTION_H


#include <string>
#include <vector>

class QuizPuzzle {
public:
    int id;
    std::string question;
    std::vector<std::string> answerOptions;
    std::string correctAnswer;
    int questionComplexity;
};


#endif //DATABASE_QUIZQUESTION_H
