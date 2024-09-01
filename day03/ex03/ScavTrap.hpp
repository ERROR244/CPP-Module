#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string str);
        ScavTrap(const ScavTrap& toCopy);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();


        void attack(const std::string& target);
        void guardGate();
};

#endif
