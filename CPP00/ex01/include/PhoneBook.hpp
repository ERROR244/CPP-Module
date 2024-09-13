#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Contacts.hpp"

class PhoneBook
{
      private:
        Contacts contacts[8];
        int index;
        int nexttoremove;
      public:
        PhoneBook();
        void addcontact(const std::string& first_name, const std::string& last_name, const std::string& nickname, const std::string& darkest_secret, const std::string& number);
        std::string getString(const std::string& text);
        void printline(int index, const std::string& firstName, const std::string& lastName, const std::string& nickname);
        void displaycontacts();
};

#endif
