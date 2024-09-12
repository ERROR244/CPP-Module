#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        // this->_type = other._type;
        std::cout << "AMateria copy assignment called" << std::endl;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses a mysterious materia on " << target.getName() << " *" << std::endl;
}
