#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        std::cout << "Cat Copy assignment operator called " << std::endl;
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meows meows meows" << std::endl;
}
