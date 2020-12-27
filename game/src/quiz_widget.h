#ifndef LAST_SAVIORS_QUIZ_WIDGET_H
#define LAST_SAVIORS_QUIZ_WIDGET_H

#include "rich_text.h"
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

    inline bool isInitialized() {
        return initialized;
    }

    static constexpr int CLICKED_CLOSE = -1;
    static constexpr int CLICKED_OUTSIDE = -2;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    QuizPuzzle puzzle;
    bool initialized = false;

    int currentUserAnswer;

    sf::RectangleShape quizOverlay;
    sfe::RichText questionText;
    std::vector<sf::RectangleShape> optionsButtons;
    std::vector<sfe::RichText> optionsTexts;
    sf::RectangleShape submitButton;
    sfe::RichText submitText;
};

#endif //LAST_SAVIORS_QUIZ_WIDGET_H
