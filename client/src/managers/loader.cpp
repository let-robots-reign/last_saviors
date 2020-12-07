#include "loader.h"

LoadingResult Loader::loadResources() {
    return LOADING_SUCCESS;
}

LoadingResult Loader::loadTextures() {
    return LOADING_SUCCESS;
}

LoadingResult Loader::loadFonts() {
    return LOADING_SUCCESS;
}

LoadingResult Loader::loadEverything() {
    if (loadResources() != LOADING_SUCCESS) {
        return ERROR_RESOURCES;
    }
    if (loadTextures() != LOADING_SUCCESS) {
        return ERROR_TEXTURES;
    }
    if (loadFonts() != LOADING_SUCCESS) {
        return ERROR_FONTS;
    }
    return LOADING_SUCCESS;
}
