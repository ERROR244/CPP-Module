#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name"), FragTrap(), ScavTrap() {
    name = "Diamond";
    setName(ClapTrap::getName());
    setNum(FragTrap::getNum(1), 1);
    setNum(ScavTrap::getNum(2), 2);
    setNum(FragTrap::getNum(3), 3);
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string str) : ClapTrap(str + "_clap_name"), FragTrap(), ScavTrap() {
    name = str;
    setName(ClapTrap::getName());
    setNum(FragTrap::getNum(1), 1);
    setNum(ScavTrap::getNum(2), 2);
    setNum(FragTrap::getNum(3), 3);
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    *this = other;
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& str) {
    ScavTrap::attack(str);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    ClapTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    ClapTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: "
              << name
              << ", ClapTrap name: "
              << ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getDName() {
  return (name);
}

void DiamondTrap::setDName(std::string name) {
    this->name = name;
}
