#include "Zombie.hpp"

int main(void)
{
    std::cout << "newZombie test \n     ";
    Zombie *zombie = newZombie("khalil");
    zombie->announce();
    delete zombie;
    std::cout << "\n\nrandomChump test \n       ";
    randomChump("sohail");
    return (0);
}