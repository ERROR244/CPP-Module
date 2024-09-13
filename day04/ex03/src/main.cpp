#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    // deep copy test
    {
        ICharacter* original = new Character("Original");
        IMateriaSource* srcc = new MateriaSource();

        srcc->learnMateria(new Ice());
        srcc->learnMateria(new Cure());

        IMateriaSource* src = new MateriaSource(*(MateriaSource*)srcc);
        delete srcc;

        AMateria* tmp = src->createMateria("ice");

        original->equip(tmp);

        ICharacter* copy = new Character(*(Character*)original);

        ICharacter* targetCharacter = new Character("Target");


        original->unequip(0);
        delete original;

        copy->use(0, *targetCharacter);

        delete targetCharacter;
        delete copy;
        delete src;
    }

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->unequip(2);
    me->unequip(3);

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->use(5, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
