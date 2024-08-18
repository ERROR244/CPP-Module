#include "point.hpp"

int main( void ) {
    // Point a(  2.7493, 4.4154 );
    // Point b( 7.1103, 4.9561 );
    // Point c( 5.4512, 12.976 );
    // Point p1( 5.02466, 8.2002 );
    // Point p2( 1.7064, 11.083 );

    // Point a( -5, 0 );
    // Point b( 0, 5 );
    // Point c( 5, 0 );
    // Point p1( 0, 0 );
    // Point p2( 5, 0 );


    std::cout << "a.X = " << a.getXValue() << " <-> a.Y = " << a.getYValue() << std::endl;
    std::cout << "b.X = " << b.getXValue() << " <-> b.Y = " << b.getYValue() << std::endl;
    std::cout << "c.X = " << c.getXValue() << " <-> c.Y = " << c.getYValue() << std::endl;
    std::cout << "p1.X = " << p1.getXValue() << " <-> p1.Y = " << p1.getYValue() << std::endl;
    std::cout << "p2.X = " << p2.getXValue() << " <-> p2.Y = " << p2.getYValue() << std::endl;

    if (bsp(a, b, c, p1) == true)
        std::cout << "Output: p1 is Inside" << std::endl;
    else
        std::cout << "Output: p1 is Outside" << std::endl;
    if (bsp(a, b, c, p2) == true)
        std::cout << "Output: p2 is Inside" << std::endl;
    else
        std::cout << "Output: p2 is Outside" << std::endl;
    return 0;
}
