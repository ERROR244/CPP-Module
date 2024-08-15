#include "main.hpp"

int main(int ac, char **av)
{
    if (ac == 4) {
        std::ofstream replacefile;
        std::string filePath = av[1];
        std::string text = readFileToString(filePath);

        text = replaceAllManual(text, av[2], av[3]);
        replacefile.open("file.replace");
        if (!replacefile.is_open()) {
            std::cerr << "Could not open the file: " << "file.replace\n";
            return 1;
        }
        replacefile << text;
        replacefile.close();
    }
    else
        std::cout << "the program that takes three parameters" << std::endl;
    return 0;
}
