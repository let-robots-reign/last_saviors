#include <iostream>
#include "iapplication.h"
#include "label.h"
#include "button.h"
#include "functor_event_handler.h"


IApplication::IApplication(const ILoader &loader, const Renderer &renderer) : renderer(renderer) {}


int IApplication::runMainMenu() {
    std::vector<Widget *> mainMenuWidgets;
    auto *mainLabel = new Label(100, 50, Coordinate(500, 300), "Last Saviors");
    auto *playButton = new Button(100, 50, Coordinate(500, 400), "Start Application");
    auto *exitButton = new Button(100, 50, Coordinate(500, 400), "Exit");
    mainMenuWidgets.push_back(mainLabel);
    mainMenuWidgets.push_back(playButton);
    mainMenuWidgets.push_back(exitButton);

    //playButton->onButtonClick += METHOD_HANDLER()

    return 0;
}

int IApplication::runGameProcess() {

    return 0;
}

int IApplication::runTowersMenu() {

    return 0;
}

int IApplication::runPuzzle() {

    return 0;
}

int IApplication::runGameOverMenu() {

    return 0;
}
