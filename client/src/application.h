#ifndef CLIENT_APPLICATION_H
#define CLIENT_APPLICATION_H

#include "managers/user_input_manager.h"
#include "managers/loader_manager.h"
#include "managers/renderer_manager.h"

class Application {
public:
    Application(RendererManager rmanager, LoaderManager lmanager, UserInputManager imanager);

    static inline Application getInstance();

    void run();

private:
    static Application instance;
    RendererManager rendererManager;
    LoaderManager loaderManager;
    UserInputManager userInputManager;
};

#endif //CLIENT_APPLICATION_H
