#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "      debug:" << std::endl;
    harl.complain("debug");
    std::cout << "      info:" << std::endl;
    harl.complain("info");
    std::cout << "      warning" << std::endl;
    harl.complain("warning");
    std::cout << "      error" << std::endl;
    harl.complain("error");
    std::cout << "      none" << std::endl;
    harl.complain("nonexistent");

    return 0;
}
