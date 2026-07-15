#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook()
{
    contactCount = 0;
    currentIndex = 0;
}

std::string PhoneBook::getInput(std::string message)
{
    std::string input;

    std::cout << message;
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Cannot be empty, try again: ";
        std::getline(std::cin, input);
    } 
    return input;
}

void PhoneBook::addContact(){
        
    contacts[currentIndex].setFirstName(getInput("First Name: "));
    contacts[currentIndex].setLastName(getInput("Last Name: "));
    contacts[currentIndex].setNickname(getInput("Nickname: "));
    contacts[currentIndex].setPhoneNumber(getInput("Phone Number: "));
    contacts[currentIndex].setDarkestSecret(getInput("Darkest Secret: "));

    currentIndex++;

    if(currentIndex == 8)
    currentIndex = 0;

    if (contactCount < 8)
        contactCount++;
}

std::string PhoneBook::formatString(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0, 9);
        str += ".";
    }

    return str;
}

void PhoneBook::searchContact()
{
    if (contactCount == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    std::cout
        << std::setw(10) << "Index" << "|"
        << std::setw(10) << "First Name" << "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "Nickname"
        << std::endl;

    int i = 0;
    while (i < contactCount)
    {
        std::cout
            << std::setw(10) << i << "|"
            << std::setw(10) << formatString(contacts[i].getFirstName()) << "|"
            << std::setw(10) << formatString(contacts[i].getLastName()) << "|"
            << std::setw(10) << formatString(contacts[i].getNickname())
            << std::endl;

        i++;
    }
    std::string index;
    std::cout << "Enter the index: ";
    std::getline(std::cin, index);

    if (index.empty())
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    bool valid = true;
    size_t j = 0;
    while (j < index.length())
    {
        if (!(index[j] >= '0' && index[j] <= '9'))
        {
            valid = false;
            break;
        }
        j++;
    }

    if (!valid)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    int int_index = std::atoi(index.c_str());
    if (int_index < 0 || int_index >= contactCount)
    {
        std::cout << "The index is out of range" << std::endl;
        return;
    }
    else
    {
        std::cout << "First Name: "
            << contacts[int_index].getFirstName() << std::endl;

        std::cout << "Last Name: "
            << contacts[int_index].getLastName() << std::endl;

        std::cout << "Nickname: "
            << contacts[int_index].getNickname() << std::endl;

        std::cout << "Phone Number: "
            << contacts[int_index].getPhoneNumber() << std::endl;

        std::cout << "Darkest Secret: "
            << contacts[int_index].getDarkestSecret() << std::endl;
    } 

}