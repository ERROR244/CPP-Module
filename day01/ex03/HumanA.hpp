#ifndef HUMANA_HBB
#define HUMANA_HBB

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& weapon;
    public:
        explicit HumanA(std::string n, Weapon& w);
        ~HumanA();
        
        void attack();
};


#endif