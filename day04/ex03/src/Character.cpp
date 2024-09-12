#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
    std::cout << "Default Character construction called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inv[i] = NULL;
}

Character::Character(Character const & other)
{
    std::cout << "Character copy construction called" << std::endl;
    *this = other;
}

Character & Character::operator=(Character const & other)
{
    std::cout << "Character copy assignment called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (this->inv[i])
                delete this->inv[i];
            if (other.inv[i])
                this->inv[i] = other.inv[i]->clone();
            else
                this->inv[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character Destructor called" << std::endl;
    for (size_t i = 0; i < 4; i++)
        delete this->inv[i];
}


std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->inv[i])
        {
            this->inv[i] = m;
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        this->inv[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3 && this->inv[idx])
        this->inv[idx]->use(target);
}
