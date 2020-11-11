#include "renderer_manager.h"

RendererManager::RendererManager(Renderer r) : renderer(std::move(r)) {}

int RendererManager::processEvent(const Event &event) {
    return 0;
}
