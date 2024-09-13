#include "Animal.hpp"

Animal::Animal() : type("none")
{
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const std::string str) : type(str)
{
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        std::cout << "Animal Copy assignment operator called " << std::endl;
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "(Animal sounds)" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}
