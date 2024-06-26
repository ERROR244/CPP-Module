#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include <iostream>

class PhoneBook
{
    private:
        struct contacts
        {
            std::string first_name;
            std::string last_name;
            std::string nickname;
            std::string darkest_secret;
            std::string number;
        };
        contacts contacts[8];
        int index;
        int nexttoremove;
    public:
        PhoneBook() : index(0), nexttoremove(0) {}

        void addcontact(const std::string& first_name, const std::string& last_name, const std::string& nickname, const std::string& darkest_secret, const std::string& number)
        {
            if (index < 8)
            {
                contacts[index].first_name = first_name;
                contacts[index].last_name = last_name;
                contacts[index].nickname = nickname;
                contacts[index].darkest_secret = darkest_secret;
                contacts[index].number = number;
                index++;
            }
            else
            {
                contacts[nexttoremove].first_name = first_name;
                contacts[nexttoremove].last_name = last_name;
                contacts[nexttoremove].nickname = nickname;
                contacts[nexttoremove].darkest_secret = darkest_secret;
                contacts[nexttoremove].number = number;
                nexttoremove++;
                if (nexttoremove == 8)
                    nexttoremove = 0;
            }
        }
        void printline(int index, const std::string& firstName, const std::string& lastName, const std::string& nickname)
        {
            std::cout << "|"
                      << std::setw(10) << std::setfill(' ') << index + 1// "1"// + std::to_string(index)
                      << "|"
                      << std::setw(10) << std::setfill(' ') << firstName
                      << "|"
                      << std::setw(10) << std::setfill(' ') << lastName
                      << "|"
                      << std::setw(10) << std::setfill(' ') << nickname
                      << "|" << std::endl;
        }
        void displaycontacts()
        {
            if (index == 0)
                std::cout << "\nError: no contacts" << std::endl;
            else
            {
                std::cout << "|-------------------------------------------|" << std::endl;
                std::cout << "|     index| FirstName|  LastName|  NickName|" << std::endl;
                for (int i = 0; i < index; ++i)
                    printline(i, contacts[i].first_name, contacts[i].last_name, contacts[i].nickname);
                std::cout << "|-------------------------------------------|";
            }
            std::cout << std::endl;
        }
};

#endif