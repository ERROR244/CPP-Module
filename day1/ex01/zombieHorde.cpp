#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        std::stringstream ss;
        ss << i;
        zombies[i].setName(name + ss.str());
    }
    return zombies;
}