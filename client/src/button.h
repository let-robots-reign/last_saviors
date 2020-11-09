#ifndef CLIENT_BUTTON_H
#define CLIENT_BUTTON_H

#include <string>
#include "widget.h"

class Button : public Widget {
public:
    Button(size_t w, size_t h, const Coordinate &coord, std::string s)
            : Widget(w, h, coord), text(std::move(s)), pressed(false) {}

    inline bool getState() {
        return pressed;
    }

    void press();
private:
    std::string text;
    bool pressed;
};

#endif //CLIENT_BUTTON_H
