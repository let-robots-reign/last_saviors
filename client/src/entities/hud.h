#ifndef CLIENT_HUD_H
#define CLIENT_HUD_H

#include <vector>
#include "widgets/widget.h"
#include "event/event.h"

class HUD {
public:
    explicit HUD(std::vector<Widget> w);

    void addWidget(const Widget &widget);

    void processEvent(const Event &event);

    void clear();

private:
    std::vector<Widget> widgets;
};

#endif //CLIENT_HUD_H
