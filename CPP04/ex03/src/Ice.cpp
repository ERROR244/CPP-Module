#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        // this->_type = other._type;
        std::cout << "Ice copy assignment called" << std::endl;
    }
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at  " << target.getName() << " *" << std::endl;
}
