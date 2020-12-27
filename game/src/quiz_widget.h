#ifndef LAST_SAVIORS_QUIZ_WIDGET_H
#define LAST_SAVIORS_QUIZ_WIDGET_H

#include "quiz_puzzle.h"
#include <SFML/Graphics.hpp>

class QuizWidget : public sf::Drawable {
public:
    QuizWidget() = default;

    explicit QuizWidget(QuizPuzzle puzzle);

    int checkButtonClicked(const sf::Vector2i &mousePos);

    inline int getCurrentUserAnswer() {
        return currentUserAnswer;
    }

    static constexpr int CLICKED_CLOSE = -1;
    static constexpr int CLICKED_OUTSIDE = -2;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    QuizPuzzle puzzle;

    int currentUserAnswer;

    sf::RectangleShape quizOverlay;
    sf::Text questionText;
    std::vector<sf::RectangleShape> optionsButtons;
    std::vector<sf::Text> optionsTexts;
    sf::RectangleShape submitButton;
    sf::Text submitText;
};

#endif //LAST_SAVIORS_QUIZ_WIDGET_H
