#include "label.h"

Label::Label(size_t w, size_t h, const Coordinate &coord, std::string s) : Widget(w, h, coord), text(std::move(s)) {}

Label::Label(std::string s) : Widget(100, 100, Coordinate(0, 0)), text(std::move(s)) {}

void Label::updateText(const std::string &newText) {
    text = newText;
}