#ifndef CLIENT_BUTTON_H
#define CLIENT_BUTTON_H

#include <string>
#include "widget.h"
#include "event.h"

class Button : public Widget {
public:
    Button(size_t w, size_t h, const Coordinate &coord, std::string s);

    inline bool getState() const {
        return pressed;
    }

    inline void press() {
        pressed = !pressed;
    }

    TEvent<Coordinate&> onButtonClick;

private:
    std::string text;
    bool pressed;
};

#endif //CLIENT_BUTTON_H
