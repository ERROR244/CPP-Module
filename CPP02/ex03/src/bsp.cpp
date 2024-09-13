#include "point.hpp"

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return std::abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)) / 2.0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    float x, y, z, x1, y1, z1, p, p1, A, A1, A2, A3;

    x = a.getXValue().toFloat();
    x1 = a.getYValue().toFloat();
    y = b.getXValue().toFloat();
    y1 = b.getYValue().toFloat();
    z = c.getXValue().toFloat();
    z1 = c.getYValue().toFloat();
    p = point.getXValue().toFloat();
    p1 = point.getYValue().toFloat();

    A = area ( x, x1, y, y1, z, z1 );
    A1 = area ( p, p1, y, y1, z, z1 );
    A2 = area ( x, x1, p, p1, z, z1 );
    A3 = area ( x, x1, y, y1, p, p1 );

    if (A == 0 || A1 == 0 ||A2 == 0 || A3 == 0)
        return (false);
    return (A == A1 + A2 + A3);
}
