#include "application.h"

#include <utility>

template<typename T>
Application<T>::Application(RendererManager rmanager, LoaderManager<T> lmanager, UserInputManager imanager)
        : rendererManager(std::move(rmanager)), loaderManager(lmanager), userInputManager(std::move(imanager)) {};

template<typename T>
Application<T> Application<T>::getInstance() {
    return Application();
}

template<typename T>
void Application<T>::run() {

}
