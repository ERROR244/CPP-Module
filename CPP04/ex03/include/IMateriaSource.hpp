#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria * m) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
