#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}

 Zombie::~Zombie () {
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::setName (std::string str){
    name = str;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;;
}

