#ifndef ICE_HPP
#define ICE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        Ice &operator=(const Ice &other);
        ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);
};


#endif
