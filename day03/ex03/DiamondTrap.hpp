#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap, public ScavTrap {
    public:
        FragTrap();
        FragTrap(const std::string str);
        FragTrap(const FragTrap& toCopy);
        ~FragTrap();


        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
