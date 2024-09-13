#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        ~Point();

        Point& operator=(const Point& other);

        Fixed getXValue( void ) const;
        Fixed getYValue( void ) const;
    private:
        Fixed x;
        Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
