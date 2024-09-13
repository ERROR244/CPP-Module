#include "Harl.hpp"

levels getLevel(std::string level)
{
    if (level == "DEBUG")
        return (DEBUG);
    if (level == "INFO")
        return (INFO);
    if (level == "WARNING")
        return (WARNING);
    if (level == "ERROR")
        return (ERROR);
    return (UNKNOWN);
}

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << "expected input:\n     ./harlFilter [complaining level](REQUIRED)" << std::endl;
        return 0;
    }
    std::string usrLevel = av[1];
    levels level = getLevel(usrLevel);
    switch (level)
    {
        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("debug");
            std::cout << "\n\n[ INFO ]" << std::endl;
            harl.complain("info");
            std::cout << "\n\n[ WARNING ]" << std::endl;
            harl.complain("warning");
            std::cout << "\n\n[ ERROR ]" << std::endl;
            harl.complain("error");
            break;
        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("info");
            std::cout << "\n\n[ WARNING ]" << std::endl;
            harl.complain("warning");
            std::cout << "\n\n[ error ]" << std::endl;
            harl.complain("error");
            break;
        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("warning");
            std::cout << "\n\n[ ERROR ]" << std::endl;
            harl.complain("error");
            break;
        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("error");
            break;
        case UNKNOWN:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
    return 0;
}