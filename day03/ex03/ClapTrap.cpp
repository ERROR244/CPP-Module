#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("unnamed"), Hit(10), Energy(10), damage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string str) : name(str), Hit(10), Energy(10), damage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->name = other.name;
    this->Hit = other.Hit;
    this->Energy = other.Energy;
    this->damage = other.damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other)
    {
        std::cout << "Copy assignment operator called " << std::endl;
        this->name = other.name;
        this->Hit = other.Hit;
        this->Energy = other.Energy;
        this->damage = other.damage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->Energy > 0 && this->Hit > 0) {
        this->Energy--;
        std::cout << "ClapTrap \033[34m\""
                << this->name
                << "\"\033[0m attacks "
                << target
                << ", causing "
                << this->damage
                << " points of damage!" << std::endl;
    }
    else if (this->Energy == 0)
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->attack\033[0m <---> no Energy left"
                  << std::endl;
    else
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->attack\033[0m <---> already dead"
                  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->Hit > 0) {
        if ((int)this->Hit - (int)amount >= 0)
            this->Hit = this->Hit - amount;
        else
            this->Hit = 0;
        std::cout << "ClapTrap \033[34m\""
                << this->name
                << "\"\033[0mtakeDamage, causing "
                << amount
                << " points of damage!" << std::endl;
    }
    else
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->takeDamage\033[0m <---> already dead"
                  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->Energy > 0 && this->Hit > 0 && this->Hit + amount <= 10) {
        this->Energy--;
        this->Hit += amount;
        std::cout << "ClapTrap \033[34m\""
                << this->name
                << "\"\033[0mbeRepaired, causing +"
                << amount
                << " points of health!" << std::endl;
    }
    else if (this->Energy == 0)
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->beRepaired\033[0m <---> no Energy left"
                  << std::endl;
    else if (this->Hit == 0)
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->beRepaired\033[0m <---> already dead"
                  << std::endl;
    else
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->beRepaired\033[0m <---> this->Hit + amount > 10"
                  << std::endl;
}
