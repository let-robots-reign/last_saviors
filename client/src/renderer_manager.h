#ifndef CLIENT_RENDERER_MANAGER_H
#define CLIENT_RENDERER_MANAGER_H

#include "manager.h"

#include <utility>
#include "renderer.h"

class RendererManager : public Manager {
public:
    RendererManager(Renderer r) : renderer(std::move(r)) {}

    int processEvent(const Event &event) override;

private:
    Renderer renderer;
};

#endif //CLIENT_RENDERER_MANAGER_H
