#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("none"), Hit(100), Energy(50), damage(20) {
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string str) : name(str), Hit(100), Energy(50), damage(20) {
    std::cout << "Init ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy ClapTrap constructor called" << std::endl;
    this->name = other.name;
    this->Hit = other.Hit;
    this->Energy = other.Energy;
    this->damage = other.damage;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->Energy > 0 && this->Hit > 0) {
        this->Energy--;
        std::cout << "ClapTrap \033[34m\""
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

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->Hit > 0) {
        this->Hit = this->Hit - amount;
        std::cout << "ClapTrap \033[34m\""
                << this->name
                << "\"\033[0mtakeDamage, causing "
                << amount
                << " points of damage!" << std::endl;
    }
    else
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->takeDamage\033[0m <---> already dead"
                  << std::endl;
    if (this->Hit < 0)
        this->Hit = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->Energy > 0 && this->Hit > 0 && this->Hit + amount <= 10) {
        this->Energy--;
        this->Hit += amount;
        std::cout << "ClapTrap \033[34m\""
                << this->name
                << "\"\033[0mbeRepaired, causing -"
                << amount
                << " points of Energy!" << std::endl;
    }
    else if (this->Energy == 0)
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->beRepaired\033[0m <---> no Energy left"
                  << std::endl;
    else if (this->Hit == 0)
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->beRepaired\033[0m <---> already dead"
                  << std::endl;
    else
        std::cout << "\033[0;31m"
                  << this->name
                  << "<->beRepaired\033[0m <---> this->Hit + amount > 10"
                  << std::endl;
}

std::string ClapTrap::getName() {
  return (name);
}

void ClapTrap::setName(std::string name) {
    this->name = name;
}

unsigned int ClapTrap::getNum(int pos) {
    if (pos == 1)
      return (Hit);
    if (pos == 2)
      return (Energy);
    if (pos == 3)
      return (damage);
    return (pos);
}

void ClapTrap::setNum(unsigned int value, int pos) {
    if (pos == 1)
      Hit = value;
    if (pos == 2)
      Energy = value;
    if (pos == 3)
      damage = value;
}

void ClapTrap::addNum(int value, int pos) {
    if (pos == 1)
      Hit += value;
    if (pos == 2)
      Energy += value;
    if (pos == 3)
      damage += value;
}
