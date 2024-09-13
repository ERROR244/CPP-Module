#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "linkedList.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*   temp[4];
        Node*       node;
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & other);
        MateriaSource & operator=(MateriaSource const & other);
        ~MateriaSource();


        void learnMateria(AMateria * m);
        AMateria* createMateria(std::string const & type);
};

#endif
