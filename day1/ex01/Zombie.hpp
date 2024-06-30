#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <sstream>
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie();
        ~Zombie();
        void announce( void );
        void setName(std::string str);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif