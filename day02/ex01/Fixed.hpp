#ifndef FIXED_HPP
#define FIXED_HPP

#include <fstream> 
#include <iostream>
#include <sstream> 
#include <string>
#include <cmath>

class Fixed {
    public:
        Fixed();
        Fixed(const int a);
        Fixed(const float a);
        Fixed(const Fixed& other);
        ~Fixed();

        Fixed& operator=(const Fixed& other);

        int  getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
    private:
        int value;
        static const int Bits = 8;
};


std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif