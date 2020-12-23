#ifndef CLIENT_APPLICATION_H
#define CLIENT_APPLICATION_H

#include "iloader.h"
#include "renderer.h"
#include "method_event_handler.h"


class IApplication {
public:
    IApplication(const ILoader &loader, const Renderer &renderer);

    static inline const IApplication getInstance() {
        return instance;
    }

    int runMainMenu();

    int runGameProcess();

    int runTowersMenu();

    int runPuzzle();

    int runGameOverMenu();

private:
    static IApplication instance;
    Renderer renderer;
};

#endif //CLIENT_APPLICATION_H
