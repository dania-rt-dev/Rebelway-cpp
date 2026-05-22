/**
 * @file student.hpp
 *
 * @brief Defines the Student class, inherits from User.
 */

#pragma once

#include <cstddef>
#include <string>

#include "user.hpp"

/**
 * @class Student
 *
 * @brief Concrete class for Student.
 */
class Student : public User
{
    public:

        /**
         * @brief Constructor for the class.
         *
         * @param id User id.
         * @param firstName User first name.
         * @param secondName User second name.
         * @param year Birth year.
         * @param month Birth month.
         * @param day Birth day.
         */
        Student
        (
            size_t id,
            std::string firstName,
            std::string secondName,
            int year,
            int month,
            int day
        );
        
        /**
         * @brief Destructor.
         */
        virtual ~Student() = default;

        /**
         * @brief Prints the full information of the Student class.
         */
        virtual void printData() const override;

        /**
         * @brief Returns the enum type of the Student.
         *
         * @return User type.
         */
        virtual TYPE getType() const override;
};