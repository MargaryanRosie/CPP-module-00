#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int contactCount;
    int currentIndex;
public:
    PhoneBook();

    std::string getInput(std::string message);
    void addContact();
    void searchContact();
    std::string formatString(std::string str);
};

#endif