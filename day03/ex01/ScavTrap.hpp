#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string str);
        ScavTrap(const ScavTrap& toCopy);
        
        ~ScavTrap();

        ScavTrap& operator=(const ScavTrap& other);

        void attack(const std::string& target);
        void guardGate();
    private:
        std::string  name;
        unsigned int Hit;
        unsigned int Energy;
        unsigned int damage;
};


#endif