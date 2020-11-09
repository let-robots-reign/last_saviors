#ifndef CLIENT_HUD_H
#define CLIENT_HUD_H

#include <vector>
#include "widget.h"
#include "event.h"

class HUD {
public:
    HUD(std::vector<Widget> w) : widgets(w) {}

    void addWidget(const Widget &widget);

    void processEvent(const Event &event);

    void clear();

private:
    std::vector<Widget> widgets;
};

#endif //CLIENT_HUD_H
