#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ClapTrap() {
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string str) : ClapTrap(str) {
    std::cout << "Init DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    std::cout << "Copy DiamondTrap constructor called" << std::endl;
    this->name = other.name;
    this->Hit = other.Hit;
    this->Energy = other.Energy;
    this->damage = other.damage;
}
