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

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();       // Pre-increment
        Fixed operator++(int);     // Post-increment
        Fixed& operator--();       // Pre-decrement
        Fixed operator--(int);     // Post-decrement

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

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
