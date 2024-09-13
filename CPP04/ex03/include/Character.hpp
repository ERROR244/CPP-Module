#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "linkedList.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria*   inv[4];
        Node*       node;
    public:
        Character(std::string const & name);
        Character(Character const & other);
        Character & operator=(Character const & other);
        ~Character();


        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
