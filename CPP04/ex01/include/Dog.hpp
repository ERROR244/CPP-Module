#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Dog : public Animal {
    public:
        Dog();
        Dog(const std::string str);
        Dog(const Dog& other);
        Dog &operator=(const Dog &other);
        ~Dog();

        void makeSound() const;
    private:
        Brain* brain;
};

#endif
