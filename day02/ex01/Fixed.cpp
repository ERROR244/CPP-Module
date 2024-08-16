#include "Fixed.hpp"

// To convert an integer number Num to a fixed point we multiply
// the number by 2^(n- 1) or we left shift the bits by (n - 1)
// where n is the fractional bits specified.

// To convert from floating-point to fixed-point, we follow this algorithm:
//
// Calculate x = floating_input * 2^(fractional_bits)
// Round x to the nearest whole number (e.g. round(x))
// Store the rounded x in an integer container

int  Fixed::getRawBits( void ) const
{
  return value;
}

void Fixed::setRawBits( int const raw )
{
  value = raw;
}

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a) : value(a << Bits) {
    std::cout << "Init constructor called" << std::endl;
}

Fixed::Fixed(const float a) : value((int)(roundf(a * (1 << Bits)))) {
    std::cout << "float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    std::cout << "Copy assignment operator called " << std::endl;
    value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
    {
        std::cout << "Copy assignment operator called " << std::endl;
        value = other.getRawBits();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
    os << other.toFloat();
    return os;
}

float Fixed::toFloat() const {
     return ((float)value / (float)(1 << Bits));
}

int Fixed::toInt() const {
    return value >> Bits;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}
