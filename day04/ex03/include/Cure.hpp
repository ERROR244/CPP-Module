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
        virtual ~Cure();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};


#endif
