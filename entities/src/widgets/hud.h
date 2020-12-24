#ifndef CLIENT_HUD_H
#define CLIENT_HUD_H

#include <vector>
#include "widget.h"
#include "event.h"

class HUD {
public:
    HUD() = default;

    explicit HUD(std::vector<Widget> w);

    void addWidget(const Widget &widget);

    void clear();

private:
    std::vector<Widget> widgets;
};

#endif //CLIENT_HUD_H
