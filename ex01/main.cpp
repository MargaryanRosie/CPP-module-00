#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook p;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "No more input" << std::endl;
            break;
        }
        if (command == "ADD")
        {
            p.addContact();
        }
    
        else if (command == "SEARCH")
        {
            p.searchContact();
        }
        else if (command == "EXIT")
        {
            break;
        }
    }
    return 0;
}