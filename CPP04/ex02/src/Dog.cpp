#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain("bark bark bark");
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        std::cout << "Dog Copy assignment operator called " << std::endl;
        delete this->brain;
        this->brain = new Brain(*other.brain);
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
