#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : name("none"), Hit(100), Energy(50), damage(20) {
    std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string str) : name(str), Hit(100), Energy(50), damage(20) {
    std::cout << "Init constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->name = other.name;
    this->Hit = other.Hit;
    this->Energy = other.Energy;
    this->damage = other.damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
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

ScavTrap::~ScavTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->Energy > 0 && this->Hit > 0) {
        this->Energy--;
        std::cout << "ScavTrap \033[34m\""
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
