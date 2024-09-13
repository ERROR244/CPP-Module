#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public FragTrap, public ScavTrap {
public:
    DiamondTrap();
    DiamondTrap(const std::string str);
    DiamondTrap(const DiamondTrap& toCopy);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI();
    void printStats();

private:
    std::string name;
};

#endif
