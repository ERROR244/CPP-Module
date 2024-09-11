#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Animal a;
    // const Animal* a = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    j->makeSound();
    i->makeSound();
    std::cout << std::endl;

    delete j;//should not create a leak
    delete i;

    return 0;
}
