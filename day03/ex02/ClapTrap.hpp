#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <fstream> 
#include <iostream>
#include <sstream> 
#include <string>
#include <cmath>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(const std::string str);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    private:
        std::string  name;
        unsigned int Hit = 10;
        unsigned int Energy = 10;
        unsigned int damage = 0;
};


#endif