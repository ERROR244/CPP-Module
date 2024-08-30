#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
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
