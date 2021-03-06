#include "hud.h"

HUD::HUD(std::vector<Widget> w) : widgets(std::move(w)) {}

void HUD::addWidget(const Widget &widget) {
    widgets.push_back(widget);
}

void HUD::clear() {
    widgets.clear();
}
