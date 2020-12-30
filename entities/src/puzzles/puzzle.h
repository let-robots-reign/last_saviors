#ifndef LAST_SAVIORS_PUZZLE_H
#define LAST_SAVIORS_PUZZLE_H

#include <cstddef>
#include <string>

class Puzzle {
private:
    size_t id{};
    std::string question;
public:
    Puzzle() {}

    Puzzle(size_t id, std::string question) : id(id), question(std::move(question)) {}

    inline std::string getQuestion() const {
        return question;
    }
};

#endif //LAST_SAVIORS_PUZZLE_H
