#include "../../include/user/user.hpp"

#include <string>
#include <iostream>

User::User
    (
        size_t id,
        std::string firstName,
        std::string secondName,
        int year,
        int month,
        int day
    )
    :
        m_id(id),
        m_firstName(std::move(firstName)),
        m_secondName(std::move(secondName)),
        m_birthDate{year, month, day}
{

};

void User::printData() const
{
    std::cout << "User with Id: " << m_id << ":\n";
    std::cout << "\tName: " << m_firstName << " " << m_secondName << "\n";
    std::cout << "\tBorn on: " << getBirthDate() << "\n";
}

size_t User::getID() const
{
    return m_id;
}

UserType User::getType() const
{
    return UserType::NONE;
}

std::string User::getFirstName() const
{
    return m_firstName;
}

void User::setFirstName(const std::string& firstName)
{
    m_firstName = std::move(firstName);
}

std::string User::getSecondName() const{
    return m_secondName;
}

void User::setSecondName(const std::string& secondName)
{
    m_secondName = std::move(secondName);
}

std::string User::getBirthDate() const
{
    return std::string{
        std::to_string(m_birthDate.m_year) + "/" +
        std::to_string(m_birthDate.m_month) + "/" +
        std::to_string(m_birthDate.m_day)
    };
}

void User::setBirthDate(int year, int month, int day)
{
    m_birthDate.m_year = year;
    m_birthDate.m_month = month;
    m_birthDate.m_day = day;
}

std::string User::enumToString(UserType userType)
{
    switch(userType)
    {
        case UserType::STUDENT:
            return "Student";
        
        case UserType::TEACHER:
            return "Teacher";

        default:
            return "";
    }
}