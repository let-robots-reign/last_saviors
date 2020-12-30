#pragma once

#include <string>
#include "quiz_puzzlez.h"

struct ClientQuiz {
    ClientQuiz() = default;

    ~ClientQuiz() = default;

    ClientQuiz(const QuizPuzzle &quiz) :
            question(quiz.question),
            optionA(quiz.answer1),
            optionB(quiz.answer2),
            optionC(quiz.answer3),
            optionD(quiz.answer4) {}

    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;

    inline std::string getQuestion() const {
        return question;
    }

    inline std::vector<std::string> getAnswerOptions() const {
        return {optionA, optionB, optionC, optionD};
    }
};
