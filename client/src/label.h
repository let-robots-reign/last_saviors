#ifndef CLIENT_LABEL_H
#define CLIENT_LABEL_H

#include <string>
#include "widget.h"

class Label : public Widget {
public:
    Label(size_t w, size_t h, const Coordinate &coord, std::string s)
            : Widget(w, h, coord), text(std::move(s)) {}

    inline std::string getText() {
        return text;
    }

    void updateText(const std::string &newText);
private:
    std::string text;
    // TODO: font, size, etc...
};

#endif //CLIENT_LABEL_H
