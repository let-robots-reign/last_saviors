#ifndef DATABASE_QUIZQUESTION_H
#define DATABASE_QUIZQUESTION_H

#include "puzzle.h"
#include <string>
#include <vector>

class QuizPuzzle : public Puzzle {
public:
    QuizPuzzle() {}

    QuizPuzzle(size_t id, const std::string &question, std::vector<std::string> answerOptions,
               size_t answerIndex) : Puzzle(id, question), answerOptions(std::move(answerOptions)),
                                            correctAnswerIndex(answerIndex) {}

    inline std::vector<std::string> getAnswerOptions() const {
        return answerOptions;
    }

    inline size_t getCorrectAnswerIndex() const {
        return correctAnswerIndex;
    }

private:
    std::vector<std::string> answerOptions;
    size_t correctAnswerIndex;
};


#endif //DATABASE_QUIZQUESTION_H
