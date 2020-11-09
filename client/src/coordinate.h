#ifndef CLIENT_COORDINATE_H
#define CLIENT_COORDINATE_H

class Coordinate {
public:
    Coordinate() : x(0), y(0) {}

    Coordinate(double px, double py) : x(px), y(py) {}

    inline double getX() {
        return x;
    }

    inline double getY() {
        return y;
    }

private:
    double x;
    double y;
};

#endif //CLIENT_COORDINATE_H
