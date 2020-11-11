#ifndef CLIENT_RENDERER_MANAGER_H
#define CLIENT_RENDERER_MANAGER_H

#include "manager.h"

#include <utility>
#include "renderer.h"

class RendererManager : public Manager {
public:
    explicit RendererManager(Renderer r);

    int processEvent(const Event &event) override;

private:
    Renderer renderer;
};

#endif //CLIENT_RENDERER_MANAGER_H
