#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default MateriaSource construction called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->temp[i] = NULL;
    this->node = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    std::cout << "MateriaSource copy construction called" << std::endl;
    this->node = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (other.temp[i])
            this->temp[i] = other.temp[i]->clone();
        else
            this->temp[i] = NULL;
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
    std::cout << "MateriaSource copy assignment called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete this->temp[i];
            if (other.temp[i])
                this->temp[i] = other.temp[i]->clone();
            else
                this->temp[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor called" << std::endl;
    for (size_t i = 0; i < 4; i++)
        delete this->temp[i];
    deleteList(node);
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->temp[i])
        {
            this->temp[i] = m;
            return;
        }
    }
    this->node = insertNode(this->node, m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->temp[i] && this->temp[i]->getType() == type)
            return (this->temp[i]->clone());
    }
    return (0);
}
