#include "quiz_widget.h"
#include "application.h"

QuizWidget::QuizWidget(QuizPuzzle quiz) : puzzle(std::move(quiz)) {
    quizOverlay.setSize(sf::Vector2f(500, 550));
    quizOverlay.setPosition(30, 30);
    quizOverlay.setFillColor(sf::Color(188, 175, 105, 200));
    quizOverlay.setOutlineColor(sf::Color(0, 0, 0));
    quizOverlay.setOutlineThickness(3);

    questionText = Application::createTextField(50, 40, puzzle.getQuestion(), 20, sf::Color(0, 0, 0));

    size_t count = puzzle.getAnswerOptions().size();
    optionsButtons.resize(count);
    optionsTexts.resize(count);
    for (size_t i = 0; i < count; ++i) {
        optionsButtons[i].setSize(sf::Vector2f(250, 30));
        optionsButtons[i].setFillColor(sf::Color(90, 106, 41));
        optionsButtons[i].setOutlineColor(sf::Color(0, 0, 0));
        optionsButtons[i].setOutlineThickness(1);
        optionsButtons[i].setPosition(50, questionText.getPosition().y + questionText.getLocalBounds().height + 50 * (i + 1));

        optionsTexts[i] = Application::createTextField(55, questionText.getPosition().y + questionText.getLocalBounds().height + 50 * (i + 1) + 5,
                                          puzzle.getAnswerOptions()[i], 18, sf::Color(255, 255, 255));
    }

    submitButton.setSize(sf::Vector2f(250, 30));
    submitButton.setPosition(sf::Vector2f(50, optionsButtons[count - 1].getPosition().y + optionsButtons[count - 1].getLocalBounds().height + 15));
    submitButton.setFillColor(sf::Color(90, 106, 41));
    submitButton.setOutlineColor(sf::Color(0, 0, 0));
    submitButton.setOutlineThickness(1);

    submitText = Application::createTextField(55, submitButton.getPosition().y + 5, "Close (-20$)", 18, sf::Color(255, 255, 255));
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
