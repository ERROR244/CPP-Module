#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string str) : ClapTrap(str) {
    std::cout << "Init ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "Copy ScavTrap constructor called" << std::endl;
    // setName(other.name);
    // setNum(other.Hit, 1);
    // setNum(other.Energy, 2);
    // setNum(other.damage, 3);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (getNum(2) > 0 && getNum(1) > 0) {
        setNum(-1, 2);
        std::cout << "ScavTrap \033[34m\""
                << getName()
                << "\"\033[0m attacks "
                << target
                << ", causing "
                << getNum(3)
                << " points of damage!" << std::endl;
    }
    else if (getNum(2) == 0)
        std::cout << "\033[0;31m"
                  << getName()
                  << "<->attack\033[0m <---> no Energy left"
                  << std::endl;
    else
        std::cout << "\033[0;31m"
                  << getName()
                  << "<->attack\033[0m <---> already dead"
                  << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap \033[34m\""
              << getName()
              << "\"\033[0m is now in Gate keeper mode. "
              << std::endl;
}
