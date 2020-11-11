#ifndef CLIENT_LOADER_H
#define CLIENT_LOADER_H

template<typename T>
class Loader {
public:
    int loadResources();

    int loadTextures();

    int loadFonts();

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
