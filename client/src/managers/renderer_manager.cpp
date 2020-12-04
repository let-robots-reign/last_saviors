#include "renderer_manager.h"

RendererManager::RendererManager(Renderer r) : renderer(std::move(r)) {}

int RendererManager::processEvent(const IEvent &event) {
    return 0;
}
