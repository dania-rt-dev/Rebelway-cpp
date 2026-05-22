#include "../../include/user/teacher.hpp"

#include <cstddef>
#include <string>

Teacher::Teacher
    (
        size_t id,
        std::string firstName,
        std::string secondName,
        int year,
        int month,
        int day
    )
    :
    User(id, firstName, secondName, year, month, day)
{
}

void Teacher::printData() const
{
    User::printData();
}

UserType Teacher::getType() const
{
    return UserType::TEACHER;
}