#ifndef CLIENT_APPLICATION_H
#define CLIENT_APPLICATION_H

#include "loader.h"
#include "renderer.h"
#include "method_event_handler.h"


class Application {
public:
    Application(const Loader &loader, const Renderer &renderer);

    static inline const Application getInstance() {
        return instance;
    }

    int runMainMenu();

    int runGameProcess();

    int runTowersMenu();

    int runPuzzle();

    int runGameOverMenu();

private:
    static Application instance;
    Loader loader;
    Renderer renderer;
};

#endif //CLIENT_APPLICATION_H
