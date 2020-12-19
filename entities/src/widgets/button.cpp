#include "button.h"

Button::Button(size_t w, size_t h, const Coordinate &coord, std::string s)
        : Widget(w, h, coord), text(std::move(s)), pressed(false) {}

Button::Button(std::string s) : Widget(100, 100, Coordinate(0, 0)),
                                text(std::move(s)), pressed(false) {}
