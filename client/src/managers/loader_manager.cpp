#include "loader_manager.h"

LoaderManager::LoaderManager(Loader l) : loader(l) {}

LoadingResult LoaderManager::load() {
    return ERROR_TEXTURES;
}

int LoaderManager::processEvent(const Event &pevent) {
    return 0;
}

Event LoaderManager::produceEvent() {
    return Event(EverythingLoaded, NoInfoEvent());
}
