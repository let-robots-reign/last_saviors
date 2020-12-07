#ifndef CLIENT_LOADER_H
#define CLIENT_LOADER_H

enum LoadingResult {
    LOADING_SUCCESS,
    ERROR_RESOURCES,
    ERROR_TEXTURES,
    ERROR_FONTS
};

class Loader {
public:
    Loader() = default;

    LoadingResult loadEverything();

    LoadingResult loadResources();

    LoadingResult loadTextures();

    LoadingResult loadFonts();
};

#endif //CLIENT_LOADER_H
