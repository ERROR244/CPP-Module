#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Animal {
    public:
        Animal();
        Animal(const std::string str);
        Animal(const Animal& other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
};

#endif
