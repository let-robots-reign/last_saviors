#ifndef CLIENT_COORDINATE_H
#define CLIENT_COORDINATE_H

class Coordinate {
public:
    Coordinate();

    Coordinate(double px, double py);

    inline double getX() const {
        return x;
    }

    inline double getY() const {
        return y;
    }

private:
    double x;
    double y;
};

#endif //CLIENT_COORDINATE_H
