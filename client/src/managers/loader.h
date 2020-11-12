#ifndef CLIENT_LOADER_H
#define CLIENT_LOADER_H

using texture_type = int;

enum LoadingResult {
    LOADING_SUCCESS,
    ERROR_RESOURCES,
    ERROR_TEXTURES,
    ERROR_FONTS
};

class Loader {
public:
    LoadingResult loadResources();

    LoadingResult loadTextures();

    LoadingResult loadFonts();

private:
    texture_type background;
    texture_type road;
    texture_type blocks;
    texture_type towers;
    texture_type citadel;
    texture_type enemies;
    texture_type font;
};

#endif //CLIENT_LOADER_H
