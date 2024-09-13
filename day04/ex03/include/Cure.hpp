#ifndef CURE_HPP
#define CURE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& other);
        Cure &operator=(const Cure &other);
        ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);
};


#endif
