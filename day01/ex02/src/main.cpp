#include <iostream>

int main(void) {
    std::string var = "HI THIS IS BRAIN";
    std::string* ptr = &var;
    std::string& ref = var;

    std::cout << &var << "\n" << ptr << "\n" << &ref << "\n\n" << std::endl;
    std::cout << var << "\n" << *ptr << "\n" << ref << std::endl;
    return 0;
}