#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; av[i]; i++)
        {
            for (int j = 0; av[i][j]; j++)
            {
                char c = av[i][j];
                if (islower(c) != 0)
                    c = c - 32;
                std::cout << c;
            }
        }
    }
    std::cout << std::endl;
    return (0);
}