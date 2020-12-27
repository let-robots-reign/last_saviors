#include "quiz_widget.h"
#include "application.h"


QuizWidget::QuizWidget(QuizPuzzle quiz) : puzzle(std::move(quiz)), currentUserAnswer(CLICKED_OUTSIDE) {
    quizOverlay.setSize(sf::Vector2f(500, 550));
    quizOverlay.setPosition(30, 30);
    quizOverlay.setFillColor(sf::Color(188, 175, 105, 200));
    quizOverlay.setOutlineColor(sf::Color(0, 0, 0));
    quizOverlay.setOutlineThickness(3);

    questionText = Application::createTextField(50, 40, 20);
    questionText << sf::Color(0, 0, 0) << puzzle.getQuestion();

    size_t count = puzzle.getAnswerOptions().size();
    optionsButtons.resize(count);
    optionsTexts.resize(count);
    for (size_t i = 0; i < count; ++i) {
        optionsButtons[i].setSize(sf::Vector2f(250, 30));
        optionsButtons[i].setFillColor(sf::Color(90, 106, 41));
        optionsButtons[i].setOutlineColor(sf::Color(0, 0, 0));
        optionsButtons[i].setOutlineThickness(1);
        optionsButtons[i].setPosition(50, questionText.getPosition().y + questionText.getLocalBounds().height + 50 * (i + 1));

        optionsTexts[i] = Application::createTextField(55, questionText.getPosition().y + questionText.getLocalBounds().height + 50 * (i + 1) + 5, 18);
        optionsTexts[i] << sf::Color(255, 255, 255) << puzzle.getAnswerOptions()[i];
    }

    submitButton.setSize(sf::Vector2f(250, 30));
    submitButton.setPosition(sf::Vector2f(50, optionsButtons[count - 1].getPosition().y + optionsButtons[count - 1].getLocalBounds().height + 15));
    submitButton.setFillColor(sf::Color(90, 106, 41));
    submitButton.setOutlineColor(sf::Color(0, 0, 0));
    submitButton.setOutlineThickness(1);

    submitText = Application::createTextField(55, submitButton.getPosition().y + 5, 18);
    submitText << sf::Color(255, 255, 255) << "Close " << sf::Color::Red << "(-20" << sf::String(L" ©)");
    initialized = true;
}


int QuizWidget::checkButtonClicked(const sf::Vector2i &mousePos) {
    sf::Vector2f pos;
    currentUserAnswer = CLICKED_OUTSIDE;
    for (size_t i = 0; i < optionsButtons.size(); ++i) {
        auto button = optionsButtons[i];
        pos = button.getPosition();
        size_t buttonWidth = button.getLocalBounds().width;
        size_t buttonHeight = button.getLocalBounds().height;
        size_t x = mousePos.x - pos.x;
        size_t y = mousePos.y - pos.y;
        if (x > 0 && x < buttonWidth && y > 0 && y < buttonHeight) {
            currentUserAnswer = i;
            break;
        }
    }

    sf::Vector2f submitPos = submitButton.getPosition();
    size_t x = mousePos.x - submitPos.x;
    size_t y = mousePos.y - submitPos.y;
    if (x > 0 && x < submitButton.getLocalBounds().width && y > 0 && y < submitButton.getLocalBounds().height) {
        currentUserAnswer = CLICKED_CLOSE;
    }

    return currentUserAnswer;
}

void QuizWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(quizOverlay, states);
    target.draw(questionText, states);
    for (size_t i = 0; i < puzzle.getAnswerOptions().size(); ++i) {
        target.draw(optionsButtons[i], states);
        target.draw(optionsTexts[i], states);
    }
    target.draw(submitButton);
    target.draw(submitText);
}
