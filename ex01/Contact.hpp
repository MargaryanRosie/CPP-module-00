#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    void setFirstName(std::string fname);
    std::string getFirstName() const;
    void setLastName(std::string lname);
    std::string getLastName() const;
    void setNickname(std::string nick);
    std::string getNickname() const;
    void setPhoneNumber(std::string num);
    std::string getPhoneNumber() const;
    void setDarkestSecret(std::string ds);
    std::string getDarkestSecret() const;
};

#endif