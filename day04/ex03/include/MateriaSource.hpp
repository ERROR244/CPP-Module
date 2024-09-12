#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *temp[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & other);
        MateriaSource & operator=(MateriaSource const & other);
        virtual ~MateriaSource();


        virtual void learnMateria(AMateria * m);
        virtual AMateria* createMateria(std::string const & type);
};

#endif
