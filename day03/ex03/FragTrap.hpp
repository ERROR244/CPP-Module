#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string str);
        FragTrap(const FragTrap& toCopy);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();


        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
