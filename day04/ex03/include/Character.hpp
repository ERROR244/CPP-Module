#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inv[4];
    public:
        Character(std::string const & name);
        Character(Character const & other);
        Character & operator=(Character const & other);
        virtual ~Character();


        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
