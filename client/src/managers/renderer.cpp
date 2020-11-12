#include "renderer.h"

Renderer::Renderer(Level plevel, HUD phud, GameState pstate) : level(std::move(plevel)), hud(std::move(phud)), state(std::move(pstate)) {}

void Renderer::renderMenu() {

}

void Renderer::renderLevel() {

}

void Renderer::renderTowersMenu() {

}

void Renderer::renderPuzzleMenu() {

}

void Renderer::renderGameOver() {

}

void Renderer::updateHUD() {

}

void Renderer::updateTileAt(size_t x, size_t y) {

}

void Renderer::updateEnemy() {

}

void Renderer::updateState(GameState newState) {

}

void Renderer::renderGrid() {

}

void Renderer::renderEnemies() {

}

void Renderer::renderWidgets() {

}
