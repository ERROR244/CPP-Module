#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("none"), Hit(10), Energy(10), damage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string str) : name(str), Hit(10), Energy(10), damage(0) {
    std::cout << "Init constructor called" << std::endl;
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
        printf("\033[0;31m%s<->attack\033[0m <---> no Energy left\n", this->name.c_str());
    else
        printf("\033[0;31m%s<->attack\033[0m <---> already dead\n", this->name.c_str());
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->Hit > 0) {
        this->Hit = this->Hit - amount;
        std::cout << "ClapTrap \033[34m\""
                << this->name
                << "\"\033[0mtakeDamage, causing "
                << amount
                << " points of damage!" << std::endl;
    }
    else
        printf("\033[0;31m%s<->takeDamage\033[0m <---> already dead\n", this->name.c_str());
    if (this->Hit < 0)
        this->Hit = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->Energy > 0 && this->Hit > 0 && this->Hit + amount <= 10) {
        this->Energy--;
        this->Hit += amount;
        std::cout << "ClapTrap \033[34m\""
                << this->name
                << "\"\033[0mbeRepaired, causing -"
                << amount
                << " points of Energy!" << std::endl;
    }
    else if (this->Energy == 0)
        printf("\033[0;31m%s<->beRepaired\033[0m <---> no Energy left\n", this->name.c_str());
    else if (this->Hit == 0)
        printf("\033[0;31m%s<->beRepaired\033[0m <---> already dead\n", this->name.c_str());
    else
        printf("\033[0;31m%s<->beRepaired\033[0m <---> this->Hit + amount > 10\n", this->name.c_str());
}
