#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        std::cout << "Dog Copy assignment operator called " << std::endl;
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark bark bark" << std::endl;
}
