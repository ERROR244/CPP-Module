#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("none") {}

ClapTrap::ClapTrap(const std::string str) : name(str) {}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string& target) {
    Energy--;
    std::cout << "ClapTrap "
              << name
              << " attacks "
              << target
              << ", causing "
              << damage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    Hit = Hit - amount;
    std::cout << "ClapTrap "
              << name
              << "takeDamage, causing "
              << amount
              << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    Energy--;
    std::cout << "ClapTrap "
              << name
              << "beRepaired, causing -"
              << amount
              << " points of Energy!" << std::endl;
}
