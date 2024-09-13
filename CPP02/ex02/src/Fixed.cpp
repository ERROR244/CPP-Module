#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int a) : value(a << Bits) {}

Fixed::Fixed(const float a) : value((int)(roundf(a * (1 << Bits)))) {}

Fixed::Fixed(const Fixed& other) : value(other.value) {}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        value = other.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
    os << other.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
  Fixed result;
  result.value = value + other.value;
  return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
  Fixed result;
  result.value = value - other.value;
  return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
  Fixed result;
  long long temp = (long long)(this->value) * (long long)(other.getRawBits());
  result.setRawBits((int)(temp >> Bits));
  return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
  Fixed result;
  if (other.value == 0) {
    std::cerr << "Division by zero error" << std::endl;
    exit(EXIT_FAILURE);
  }
  long long temp = ((long long)(this->value) << Bits) / other.getRawBits();
  result.setRawBits((int)(temp));
  return result;
}

Fixed& Fixed::operator++() {
    ++value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++value;
    return temp;
}

Fixed& Fixed::operator--() {
    --value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --value;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a > b) ? a : b;
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
  return (float)value / (float)(1 << Bits);
}

int Fixed::toInt() const {
  return value >> Bits;
}
