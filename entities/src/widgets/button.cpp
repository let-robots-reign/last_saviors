#include "button.h"

Button::Button(size_t w, size_t h, const Coordinate &coord, std::string s)
        : Widget(w, h, coord), text(std::move(s)), pressed(false) {}
