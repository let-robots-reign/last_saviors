#include "application.h"

#include <utility>

Application::Application(RendererManager rmanager, LoaderManager lmanager, UserInputManager imanager)
        : rendererManager(std::move(rmanager)), loaderManager(std::move(lmanager)), userInputManager(std::move(imanager)) {};

Application Application::getInstance() {
    return instance;
}

void Application::run() {

}
