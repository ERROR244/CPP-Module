#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string const _type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();


        std::string const & getType() const; //Returns the materia type

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};


#endif
