#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Brain {
    public:
        Brain();
        Brain(std::string str);
        Brain(const Brain& other);
        Brain &operator=(const Brain& other);
        ~Brain();

        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);

    private:
        std::string ideas[100];
};


#endif
