#include <iostream>
#include "iapplication.h"
#include "label.h"
#include "functor_event_handler.h"


IApplication::IApplication(const ILoader &loader, const Renderer &renderer) : renderer(renderer) {}


int IApplication::runMainMenu() {
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
