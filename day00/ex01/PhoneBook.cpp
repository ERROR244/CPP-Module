#include "PhoneBook.hpp"

std::string Contacts::get_contact_field(int field)
{
    if (field == 1)
      return (first_name);
    if (field == 2)
      return (last_name);
    if (field == 3)
      return (nickname);
    if (field == 4)
      return (darkest_secret);
    if (field == 5)
      return (number);
    return ("none");
}

void Contacts::set_contact_field(int field, std::string string)
{
    if (field == 1)
      first_name = string;
    if (field == 2)
      last_name = string;
    if (field == 3)
      nickname = string;
    if (field == 4)
      darkest_secret = string;
    if (field == 5)
      number = string;
}

PhoneBook::PhoneBook() : index(0), nexttoremove(0) {}

void PhoneBook::addcontact(const std::string& first_name, const std::string& last_name, const std::string& nickname, const std::string& darkest_secret, const std::string& number)
{
    if (index < 8)
    {
        contacts[index].set_contact_field(1, first_name);
        contacts[index].set_contact_field(2, last_name);
        contacts[index].set_contact_field(3, nickname);
        contacts[index].set_contact_field(4, darkest_secret);
        contacts[index].set_contact_field(5, number);
        index++;
    }
    else
    {
        contacts[index].set_contact_field(1, first_name);
        contacts[index].set_contact_field(2, last_name);
        contacts[index].set_contact_field(3, nickname);
        contacts[index].set_contact_field(4, darkest_secret);
        contacts[index].set_contact_field(5, number);
        nexttoremove++;
        if (nexttoremove == 8)
            nexttoremove = 0;
    }
}

std::string PhoneBook::getString(const std::string& text)
{
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    else
        return text;
}

void PhoneBook::printline(int index, const std::string& firstName, const std::string& lastName, const std::string& nickname)
{
    std::cout << "|"
              << std::setw(10) << std::right << index
              << "|"
              << std::setw(10) << std::right << getString(firstName)
              << "|"
              << std::setw(10) << std::right << getString(lastName)
              << "|"
              << std::setw(10) << std::right << getString(nickname)
              << "|" << std::endl;
}

void PhoneBook::displaycontacts()
{
    if (index == 0)
        std::cout << "\nError: no contacts\n";
    else
    {
        std::cout << "|-------------------------------------------|\n";
        std::cout << "|     index| FirstName|  LastName|  NickName|\n";
        for (int i = 0; i < index; ++i)
            printline(i, contacts[i].get_contact_field(1), contacts[i].get_contact_field(2), contacts[i].get_contact_field(3));
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
                std::cout << "first name: " << contacts[userIndex].get_contact_field(1) << "\n";
                std::cout << "last name: " << contacts[userIndex].get_contact_field(2) << "\n";
                std::cout << "nickname: " << contacts[userIndex].get_contact_field(3) << "\n";
                std::cout << "number: " << contacts[userIndex].get_contact_field(4) << "\n";
                std::cout << "darkest_secret: " << contacts[userIndex].get_contact_field(5) << "\n";
            }
        }
        else
            std::cout << "\nInvalid input. Please enter a valid index.\n";
    }
    std::cout << std::endl;
}
