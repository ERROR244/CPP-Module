#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const std::string str);
        WrongCat(const WrongCat& other);
        WrongCat &operator=(const WrongCat &other);
        ~WrongCat();

        void makeSound() const;
};

#endif
