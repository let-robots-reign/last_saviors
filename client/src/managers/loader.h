#ifndef CLIENT_LOADER_H
#define CLIENT_LOADER_H

enum LoadingResult {
    SUCCESS,
    ERROR_RESOURCES,
    ERROR_TEXTURES,
    ERROR_FONTS
};

template<typename T> // T is the type of textures
class Loader {
public:
    LoadingResult loadResources();

    LoadingResult loadTextures();

    LoadingResult loadFonts();

private:
    T background;
    T road;
    T blocks;
    T towers;
    T citadel;
    T enemies;
    T font;
};
// TODO: template or not?

#endif //CLIENT_LOADER_H
