#include "HumanA.hpp"

HumanA::HumanA (std::string n, Weapon& w) : name(n), weapon(w) {}
HumanA::~HumanA () {
    std::cout << name << " is destroyed." << std::endl;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
