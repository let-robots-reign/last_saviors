#include "label.h"

Label::Label(size_t w, size_t h, const Coordinate &coord, std::string s) : Widget(w, h, coord), text(std::move(s)) {}

void Label::updateText(const std::string &newText) {
    text = newText;
}