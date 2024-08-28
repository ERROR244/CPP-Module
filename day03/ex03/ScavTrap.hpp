#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string str);
        ScavTrap(const ScavTrap& toCopy);
        ~ScavTrap();


        void attack(const std::string& target);
        void guardGate();
};

#endif
