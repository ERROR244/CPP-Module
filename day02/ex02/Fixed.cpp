#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a) : value(a << Bits) {
    std::cout << "Init constructor called" << std::endl;
}

Fixed::Fixed(const float a) : value(static_cast<int>(roundf(a * (1 << Bits)))) {
    std::cout << "float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
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

Fixed Fixed::operator+(const Fixed& other) {
    Fixed result;
    result.value = value + other.value;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
    os << other.toFloat();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


int  Fixed::getRawBits( void ) const
{
    return value;
}

void Fixed::setRawBits( int const raw )
{
    value = raw;
}



float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << Bits);
}

int Fixed::toInt() const {
    return value >> Bits;
}
