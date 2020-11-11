#ifndef CLIENT_RENDERER_H
#define CLIENT_RENDERER_H

#include <utility>

#include "entitites/hud.h"
#include "entities/level.h"

class Renderer {
public:
    Renderer(Level plevel, HUD phud) : level(std::move(plevel)), hud(std::move(phud)) {}

    void renderMenu();

    void renderLevel();

    void renderGameOver();

    void updateHUD();

    void updateTileAt(size_t x, size_t y);

    void updateEnemies();

private:
    Level level;
    HUD hud;

    void renderGrid();

    void renderEnemies();

    void renderWidgets();
};

#endif //CLIENT_RENDERER_H
