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

    // deep copy

    Dog basic1;
    {
        Dog tmp1 = basic1;
        tmp1.makeSound();
    }

    basic1.makeSound();
    
    Cat basic2;
    {
        Cat tmp2;
        tmp2 = basic2;
        tmp2.makeSound();
    }

    basic2.makeSound();

    // array test
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
