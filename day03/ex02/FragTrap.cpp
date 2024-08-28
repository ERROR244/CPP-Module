#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string str) : ClapTrap(str) {
    std::cout << "Init FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "Copy FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (getNum(2) > 0 && getNum(1) > 0) {
        setNum(-1, 2);
        std::cout << "FragTrap \033[34m\""
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

void FragTrap::highFivesGuys(void) {
    std::cout << "High five! ✋ from "
              << getName()
              << " FragTrap" << std::endl;
}
