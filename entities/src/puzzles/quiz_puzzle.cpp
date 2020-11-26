#include "quiz_puzzle.h"

#include <utility>

QuizPuzzle::QuizPuzzle(size_t id, const std::string &question, size_t puzzleComplexity,
                       std::vector<std::string> answerOptions, std::string correctAnswer)
        : Puzzle(id, question, puzzleComplexity), answerOptions(std::move(answerOptions)),
        correctAnswer(std::move(correctAnswer)) {}

QuizPuzzle::QuizPuzzle() = default;
