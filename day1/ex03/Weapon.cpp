#include "Weapon.hpp"

Weapon::Weapon (std::string t) : type(t) {}
Weapon::~Weapon () {
    std::cout << "weapon" << " is destroyed." << std::endl;
}

const std::string& Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string typeToSet)
{
    type = typeToSet;
}
