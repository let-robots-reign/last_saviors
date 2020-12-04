#include "loader_manager.h"

LoaderManager::LoaderManager(const Loader &l) : loader(l) {}

LoadingResult LoaderManager::load() {
    return ERROR_TEXTURES;
}

int LoaderManager::processEvent(const IEvent &pevent) {
    return 0;
}

IEvent *LoaderManager::produceEvent() {
    return new NoInfoEvent(EverythingLoaded);
}
