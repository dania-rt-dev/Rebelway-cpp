#include "../../include/user/student.hpp"

#include <cstddef>
#include <string>

Student::Student
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

void Student::printData() const
{
    User::printData();
}

UserType Student::getType() const
{
    return UserType::STUDENT;
}
