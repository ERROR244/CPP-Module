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
    std::string name;
    std::string number;

    while (1)
    {
        std::cin >> key;

        if (eofcheck() == 1)
            break;
        else if (key == "exit" || key == "e")
            break;
        else if (key == "add" || key == "a")
        {
            std::cin >> name;
            if (eofcheck() == 1)
                break;
            std::cin >> number;
            if (eofcheck() == 1)
                break;
            manager.addcontact(name, number);
        }
        else if (key == "display" || key == "d")
            manager.displaycontacts();
        else
            std::cout << "unkonwn key: \"" << key << "\"" << std::endl;
    }
    return 0;
}