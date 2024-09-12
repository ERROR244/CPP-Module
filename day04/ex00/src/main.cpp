#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* meta = new Animal();
    const WrongAnimal* h = new WrongCat();

    std::cout << "\n";

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << h->getType() << " " << std::endl;

    std::cout << "\n";

    i->makeSound(); //will output the cat sound!
    j->makeSound(); //will output the dog sound!
    h->makeSound();
    meta->makeSound();

    std::cout << "\n";

    delete meta;
    delete i;
    delete j;
    delete h;

    return 0;
}
