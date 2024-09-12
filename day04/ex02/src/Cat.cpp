#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain("meows meows meows");
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        std::cout << "Cat Copy assignment operator called " << std::endl;
        delete this->brain;
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meows meows meows" << std::endl;
}
