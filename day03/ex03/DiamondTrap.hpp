#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap();
        DiamondTrap(const std::string str);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();

        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void attack(const std::string& str);
        void whoAmI();
        std::string getDName();
        void setDName(std::string name);
    private:
        std::string name;
};

#endif
