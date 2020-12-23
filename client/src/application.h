#ifndef CLIENT_APPLICATION_H
#define CLIENT_APPLICATION_H

#include "iloader.h"
#include "renderer.h"
#include "method_event_handler.h"


class Application {
public:
    Application(const ILoader &loader, const Renderer &renderer);

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
    Renderer renderer;
};

#endif //CLIENT_APPLICATION_H
