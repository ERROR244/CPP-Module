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
        ClapTrap(const ClapTrap& toCopy);
        ~ClapTrap();



        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        std::string  name;
        unsigned int Hit;
        unsigned int Energy;
        unsigned int damage;
};


#endif