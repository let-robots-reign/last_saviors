#ifndef CLIENT_APPLICATION_H
#define CLIENT_APPLICATION_H

#include "managers/user_input_manager.h"
#include "managers/loader_manager.h"
#include "managers/renderer_manager.h"

template<typename T>
class Application {
public:
    Application() = default;

    Application(RendererManager rmanager, LoaderManager<T> lmanager, UserInputManager imanager);

    static inline Application getInstance();

    void run();

private:
    static Application instance;
    RendererManager rendererManager;
    LoaderManager<T> loaderManager;
    UserInputManager userInputManager;
};

#endif //CLIENT_APPLICATION_H
