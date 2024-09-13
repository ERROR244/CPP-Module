#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const std::string str);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal &operator=(const WrongAnimal &other);
        ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
};

#endif
