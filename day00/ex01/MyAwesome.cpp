#include "PhoneBook.hpp"
#include "Contacts.hpp"

int eofcheck()
{
    if (std::cin.eof())
    {
        std::cout << "\nEOF reached. Exiting..." << std::endl;
        return (1);
    }
    return (0);
}

int main()
{
    PhoneBook manager;
    std::string key;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string darkest_secret;


    while (1)
    {
        std::cout << "~>";
        std::getline(std::cin, key);

        if (eofcheck() == 1)
            break;
        else if (key == "EXIT")
            break;
        else if (key == "ADD")
        {
            std::cout << std::endl;
            do {
                std::cout << "get first name(REQUIRED): ";
                std::getline(std::cin, first_name);
                if (eofcheck() == 1)
                    break;
            } while (first_name.empty());
            std::cout << "get last name: ";
            std::getline(std::cin, last_name);
            if (eofcheck() == 1)
                break;
            std::cout << "get nickname: ";
            std::getline(std::cin, nickname);
            if (eofcheck() == 1)
                break;
            std::cout << "get number: ";
            std::getline(std::cin, number);
            if (eofcheck() == 1)
                break;
            std::cout << "get darkest_secret: ";
            std::getline(std::cin, darkest_secret);
            if (eofcheck() == 1)
                break;
            std::cout << std::endl;
            manager.addcontact(first_name, last_name, nickname, darkest_secret, number);
            std::cout << "New contact added succesfully\n" << std::endl;
        }
        else if (key == "SEARCH")
            manager.displaycontacts();
    }
    return 0;
}
