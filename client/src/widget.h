#ifndef CLIENT_WIDGET_H
#define CLIENT_WIDGET_H

#include <cstddef>
#include "coordinate.h"

class Widget {
public:
    Widget(size_t w, size_t h, const Coordinate &coord) : width(w), height(h), leftCorner(coord) {}
private:
    size_t width;
    size_t height;
    Coordinate leftCorner;
};

#endif //CLIENT_WIDGET_H
