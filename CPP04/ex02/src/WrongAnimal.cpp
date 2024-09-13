#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("none")
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string str) : type(str)
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        std::cout << "WrongAnimal Copy assignment operator called " << std::endl;
        this->type = other.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "(WrongAnimal sounds)" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}
