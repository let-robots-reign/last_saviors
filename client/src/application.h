#ifndef CLIENT_APPLICATION_H
#define CLIENT_APPLICATION_H

#include "user_input_manager.h"
#include "loader_manager.h"
#include "renderer_manager.h"

template<typename T>
class Application {
public:
    Application() {} // TODO: think about Application constructor

    static Application getInstance();

    void run();

private:
    static Application instance;
    RendererManager rendererManager;
    LoaderManager<T> loaderManager; // TODO: same
    UserInputManager userInputManager;
};

#endif //CLIENT_APPLICATION_H
