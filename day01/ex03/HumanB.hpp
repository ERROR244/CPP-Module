#ifndef HUMANB_HBB
#define HUMANB_HBB

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        Weapon* weapon;
        std::string name;
    public:
        explicit HumanB(std::string n);
        ~HumanB();
        
        void attack();
        void setWeapon(Weapon& w);
};



#endif