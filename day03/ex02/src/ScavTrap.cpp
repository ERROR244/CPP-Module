#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "Default ScavTrap constructor called" << std::endl;
	this->name = "unnamed";
    this->Hit = 100;
	this->Energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const std::string str) : ClapTrap(str) {
    std::cout << "Default ScavTrap constructor called" << std::endl;
    this->name = str;
    this->Hit = 100;
	this->Energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "Copy ScavTrap constructor called" << std::endl;
    this->name = other.name;
    this->Hit = other.Hit;
    this->Energy = other.Energy;
    this->damage = other.damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other)
    {
        std::cout << "ScavTrap Assignation operator called" << std::endl;
        this->name = other.name;
        this->Hit = other.Hit;
        this->Energy = other.Energy;
        this->damage = other.damage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
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
    else if (this->Hit == 0)
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->attack\033[0m <---> already dead"
                  << std::endl;
    else
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->attack\033[0m <---> no Energy left"
                  << std::endl;
}

void ScavTrap::guardGate() {
    if (this->Energy > 0 && this->Hit > 0)
    {
        std::cout << "ScavTrap \033[34m\""
                  << this->name
                  << "\"\033[0m is now in Gate keeper mode. "
                  << std::endl;
    }
    else if (this->Hit == 0)
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->guardGate mode\033[0m <---> already dead"
                  << std::endl;
    else
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->guardGate mode\033[0m <---> no Energy left"
                  << std::endl;
}
