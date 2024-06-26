#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class PhoneBook
{
    private:
        struct contacts
        {
            std::string name;
            std::string number;
        };
        contacts contacts[8];
        int index;
        int nexttoremove;
    public:
        PhoneBook() : index(0), nexttoremove(0) {}

        void addcontact(const std::string& name, const std::string& number)
        {
            if (index < 8)
            {
                contacts[index].name = name;
                contacts[index].number = number;
                index++;
            }
            else
            {
                contacts[nexttoremove].name = name;
                contacts[nexttoremove].number = number;
                nexttoremove++;
                if (nexttoremove == 8)
                    nexttoremove = 0;
            }
        }
        void displaycontacts()
        {
            std::cout << "Contacts:" << std::endl;
            for (int i = 0; i < index; ++i)
            {
                std::cout << "Name: " << contacts[i].name << ", Phone Number: " << contacts[i].number << std::endl;
            }
            std::cout << std::endl;
        }
};

#endif