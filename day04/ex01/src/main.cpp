#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    int size = 10;

    const Animal* meta[size];

    for (int i = 0; i < size; i++)
    {
        if (i < (int)(size/2))
            meta[i] = new Dog();
        else
            meta[i] = new Cat();
        std::cout << std::endl;
        meta[i]->makeSound();
        std::cout << std::endl;
    }

    for (int i = 0; i < size; i++)
        delete meta[i];

    return 0;
}
