#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other){
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
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int  Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}
void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}
