#ifndef DATABASE_QUIZQUESTION_H
#define DATABASE_QUIZQUESTION_H

#include "puzzle.h"
#include <string>
#include <vector>

class QuizPuzzle : Puzzle {
private:
    std::vector<std::string> answerOptions;
    std::string correctAnswer;
public:
    QuizPuzzle();

    QuizPuzzle(size_t id, const std::string &question, size_t puzzleComplexity,
               std::vector<std::string> answerOptions, std::string correctAnswer);
};


#endif //DATABASE_QUIZQUESTION_H
