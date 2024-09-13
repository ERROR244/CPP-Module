#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Diamond_clap_name"),
    FragTrap("Diamond_clap_name"),
    ScavTrap("Diamond_clap_name"),
    name("Diamond")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->Hit = 100;
    this->Energy = 50;
    this->damage = 30;
}

DiamondTrap::DiamondTrap(const std::string str)
    : ClapTrap(str + "_clap_name"),
    FragTrap(str + "_clap_name"),
    ScavTrap(str + "_clap_name"),
    name(str)
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    this->Hit = 100;
    this->Energy = 50;
    this->damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        std::cout << "DiamondTrap assignment operator called" << std::endl;
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& str) {
    ScavTrap::attack(str);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: "
              << this->name
              << ", ClapTrap name: "
              << ClapTrap::name << std::endl;
}


void DiamondTrap::printStats() {
    std::cout << "DiamondTrap name: "
              << this->name
              << ", ClapTrap name: "
              << ClapTrap::name
              << ", Hit: "
              << this->Hit
              << ", Energy: "
              << this->Energy
              << ", damage: "
              << this->damage
              << std::endl;
}
