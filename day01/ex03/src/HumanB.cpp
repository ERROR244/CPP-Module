#include "HumanB.hpp"

HumanB::HumanB (std::string n) : name(n) {}
HumanB::~HumanB () {
    std::cout << name << " is destroyed." << std::endl;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks with bare hands!" << std::endl;
}

void HumanB::setWeapon(Weapon &w) {
        weapon = &w;
}
