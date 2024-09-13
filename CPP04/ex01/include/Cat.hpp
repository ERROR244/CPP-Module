#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Cat : public Animal {
    public:
        Cat();
        Cat(const std::string str);
        Cat(const Cat& other);
        Cat &operator=(const Cat &other);
        ~Cat();

        void makeSound() const;
    private:
        Brain* brain;
};

#endif
