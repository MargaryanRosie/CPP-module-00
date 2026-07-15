#include <string>
#include "Contact.hpp"

void Contact::setFirstName(std::string fname)
{
    firstName = fname;
}
std::string Contact::getFirstName() const
{
    return firstName;
}

void Contact::setLastName(std::string lname)
{
    lastName = lname;
}
std::string Contact::getLastName() const
{
    return lastName;
}

void Contact::setNickname(std::string nick)
{
    nickname = nick;
}
std::string Contact::getNickname() const
{
    return nickname;
}

void Contact::setPhoneNumber(std::string num)
{
    phoneNumber = num;
}
std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

void Contact::setDarkestSecret(std::string ds)
{
    darkestSecret = ds;
}
std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}