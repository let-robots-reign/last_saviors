#ifndef CLIENT_RENDERER_H
#define CLIENT_RENDERER_H

#include <utility>

#include "hud.h"
#include "level.h"

enum RenderingResult {
    RENDERING_SUCCESS,
    RENDERING_MENU_ERROR,
    RENDERING_LEVEL_ERROR,
    RENDERING_GAME_OVER_ERROR,
    RENDERING_GRID_ERROR,
    RENDERING_ENEMIES_ERROR,
    RENDERING_WIDGETS_ERROR
};

class Renderer {
public:
    Renderer(Level plevel, HUD phud);

    void renderMenu();

    void renderLevel();

    void renderTowersMenu();

    void renderPuzzleMenu();

    void renderGameOver();

    void updateHUD();

    void updateTileAt(size_t x, size_t y);

    void updateEnemy();

    inline Level getLevel() {
        return level;
    }

    inline HUD getHUD() {
        return hud;
    }

private:
    Level level;
    HUD hud;

    void renderGrid();

    void renderEnemies();

    void renderWidgets();
};

#endif //CLIENT_RENDERER_H
