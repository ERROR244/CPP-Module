#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Contacts
{
    public:
        std::string get_contact_field(int field);
        void set_contact_field(int field, std::string string);
    private:
      std::string first_name;
      std::string last_name;
      std::string nickname;
      std::string darkest_secret;
      std::string number;
};

#endif
