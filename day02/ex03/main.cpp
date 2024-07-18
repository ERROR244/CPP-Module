#include "point.hpp"

int main( void ) {
    Point p1( 6.034f, 4.034f );
    Point p2( 3.85f, 12.5f );
    Point p3;

    p3 = p2;
    std::cout << p1.getXValue() << std::endl;
    std::cout << p1.getYValue() << std::endl;
    std::cout << p2.getXValue() << " <-> " << p3.getXValue() << std::endl;
    std::cout << p2.getYValue() << " <-> " << p3.getYValue() << std::endl;

    
    // std::cout << << std::endl;
    // std::cout << << std::endl;
    // std::cout << << std::endl;
    // std::cout << << std::endl;
    // std::cout << << std::endl;

    return 0;
}