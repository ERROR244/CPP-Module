#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string str) : ClapTrap(str) {
    std::cout << "Init DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other) {
    std::cout << "Copy DiamondTrap constructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    if (getNum(2) > 0 && getNum(1) > 0) {
        setNum(-1, 2);
        std::cout << "DiamondTrap \033[34m\""
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
