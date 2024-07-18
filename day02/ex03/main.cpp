#include "point.hpp"

int main( void ) {
    Point a( 0.5, 0.5 );
    Point b( 10.5, 30.5 );
    Point c( 20.5, 0.5 );
    Point p( 10.5, 15.5 );

    std::cout << "a.X = " << a.getXValue() << " <-> a.Y = " << a.getYValue() << std::endl;
    std::cout << "b.X = " << b.getXValue() << " <-> b.Y = " << b.getYValue() << std::endl;
    std::cout << "c.X = " << c.getXValue() << " <-> c.Y = " << c.getYValue() << std::endl;
    std::cout << "p.X = " << p.getXValue() << " <-> p.Y = " << p.getYValue() << std::endl;

    if (bsp(a, b, c, p) == true)
        std::cout << "Output: Inside" << std::endl;
    else
        std::cout << "Output: Outside" << std::endl;
    return 0;
}