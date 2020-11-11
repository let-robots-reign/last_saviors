#include "loader_manager.h"

template<typename T>
LoaderManager<T>::LoaderManager(Loader<T> l) : loader(l) {}

template<typename T>
LoadingResult LoaderManager<T>::load() {
    return ERROR_TEXTURES;
}

template<typename T>
int LoaderManager<T>::processEvent(const Event &pevent) {
    return 0;
}

template<typename T>
Event LoaderManager<T>::produceEvent() {
    event.type = EverythingLoaded;
    event.info = NoInfoEvent();
    return event;
}
