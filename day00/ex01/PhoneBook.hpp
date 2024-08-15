#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class PhoneBook
{
    private:
        struct Contacts
        {
            std::string first_name;
            std::string last_name;
            std::string nickname;
            std::string darkest_secret;
            std::string number;
        };
        Contacts contacts[8];
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
        std::string getString(const std::string& text)
        {
            if (text.length() > 10)
                return text.substr(0, 9) + ".";
            else
                return text;
        }
        void printline(int index, const std::string& firstName, const std::string& lastName, const std::string& nickname)
        {
            std::cout << "|"
                      << std::setw(10) << index
                      << "|"
                      << std::setw(10) << getString(firstName)
                      << "|"
                      << std::setw(10) << getString(lastName)
                      << "|"
                      << std::setw(10) << getString(nickname)
                      << "|" << std::endl;
        }
        void displaycontacts()
        {
            if (index == 0)
                std::cout << "\nError: no contacts\n";
            else
            {
                std::cout << "|-------------------------------------------|\n";
                std::cout << "|     index| FirstName|  LastName|  NickName|\n";
                for (int i = 0; i < index; ++i)
                    printline(i, contacts[i].first_name, contacts[i].last_name, contacts[i].nickname);
                std::cout << "|-------------------------------------------|\n";
                int userIndex;
                std::string userinput;
                std::cout << "index->";
                std::getline(std::cin, userinput);
                std::istringstream iss(userinput);
                if (iss >> userIndex)
                {
                    if (userIndex < 0 || userIndex >= index)
                        std::cout << "\nthe index is out of rang\n";
                    else
                    {
                        std::cout << "first name: " << contacts[userIndex].first_name << "\n";
                        std::cout << "last name: " << contacts[userIndex].last_name << "\n";
                        std::cout << "nickname: " << contacts[userIndex].nickname << "\n";
                        std::cout << "number: " << contacts[userIndex].number << "\n";
                        std::cout << "darkest_secret: " << contacts[userIndex].darkest_secret << "\n";
                    }
                }
                else
                    std::cout << "\nInvalid input. Please enter a valid index.\n";
            }
            std::cout << std::endl;
        }
};

#endif
