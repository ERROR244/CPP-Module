#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "Default FragTrap constructor called" << std::endl;
	this->name = "none";
    this->Hit = 100;
	this->Energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const std::string str) : ClapTrap(str) {
    std::cout << "Default FragTrap constructor called" << std::endl;
    this->name = str;
    this->Hit = 100;
	this->Energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "Copy FragTrap constructor called" << std::endl;
    this->name = other.name;
    this->Hit = other.Hit;
    this->Energy = other.Energy;
    this->damage = other.damage;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other)
    {
        std::cout << "FragTrap Assignation operator called" << std::endl;
        this->name = other.name;
        this->Hit = other.Hit;
        this->Energy = other.Energy;
        this->damage = other.damage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->Energy > 0 && this->Hit > 0) {
        this->Energy--;
        std::cout << "FragTrap \033[34m\""
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

void FragTrap::highFivesGuys(void) {
    if (this->Energy > 0 && this->Hit > 0)
    {
        std::cout << "High five! ✋ from "
                  << this->name
                  << " FragTrap" << std::endl;
    }
    else if (this->Energy == 0)
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->guardGate mode\033[0m <---> no Energy left"
                  << std::endl;
    else
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->guardGate mode\033[0m <---> already dead"
                  << std::endl;
}
