#include "Fixed.hpp"

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
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float a) : value((int)(roundf(a * (1 << Bits)))) {
    std::cout << "float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
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
