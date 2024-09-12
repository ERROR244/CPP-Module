#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        // this->_type = other._type;
        std::cout << "Cure copy assignment called" << std::endl;
    }
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "*  heals " << target.getName() << "’s wounds *" << std::endl;
}
