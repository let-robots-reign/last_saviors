#ifndef CLIENT_COORDINATE_H
#define CLIENT_COORDINATE_H

#include "cmath"

class Coordinate {
   public:
    Coordinate();

    Coordinate(double px, double py);

    inline double getX() const { return x; }

    inline double getY() const { return y; }

    static double distance(const Coordinate &first_coordinate,
                           const Coordinate &second_coordinate);

   private:
    double x;
    double y;
};

#endif  // CLIENT_COORDINATE_H
