#include "Zombie.hpp"

int size = 5;

int main(void)
{
    Zombie* zombies = zombieHorde(size, "zombie");
    
    for (int i = 0; i < size; ++i) {
        zombies[i].announce();
    }
    delete [] zombies;
    return (0);
}