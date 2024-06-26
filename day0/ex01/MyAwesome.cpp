#include "PhoneBook.h"

extern const int MAX_CONTACTS = 8; 

int eofcheck()
{
    if (std::cin.eof())
    {
        std::cout << "EOF reached. Exiting..." << std::endl;
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
   
   
    // std::string firsname;
    // std::string number;

    while (1)
    {
        std::cin >> key;

        if (eofcheck() == 1)
            break;
        else if (key == "EXIT" || key == "e")
            break;
        else if (key == "ADD" || key == "a")
        {
            std::cout << std::endl;
            std::cout << "get first name: ";
            std::cin >> first_name;
            if (eofcheck() == 1)
                break;
            std::cout << "get last name: ";
            std::cin >> last_name;
            if (eofcheck() == 1)
                break;
            std::cout << "get nickname: ";
            std::cin >> nickname;
            if (eofcheck() == 1)
                break;
            std::cout << "get number: ";
            std::cin >> number;
            if (eofcheck() == 1)
                break;
            std::cout << "get darkest_secret: ";
            std::cin >> darkest_secret;
            if (eofcheck() == 1)
                break;
            std::cout << std::endl;




            manager.addcontact(first_name, last_name, nickname, darkest_secret, number);
            std::cout << "New contact added succesfully\n" << std::endl;
        }
        else if (key == "SEARCH" || key == "s")
            manager.displaycontacts();
        // else
        //     std::cout << "unkonwn key: \"" << key << "\"" << std::endl;
    }
    return 0;
}