#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string str) : ClapTrap(str) {
    std::cout << "Init FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "Copy FragTrap constructor called" << std::endl;
    this->name = other.name;
    this->Hit = other.Hit;
    this->Energy = other.Energy;
    this->damage = other.damage;
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
    std::cout << "High five! ✋ from FragTrap" << std::endl;
}
