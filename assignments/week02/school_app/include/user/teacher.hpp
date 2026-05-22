/**
 * @file teacher.hpp
 *
 * @brief Defines the Teacher class, inherits from User.
 */

#pragma once

#include <cstddef>
#include <string>

#include "user.hpp"

/**
 * @class Teacher
 *
 * @brief Concrete class for Teacher.
 */
class Teacher : public User
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
        Teacher
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
         virtual ~Teacher() = default;

        /**
         * @brief Prints the full information of the Teacher class.
         */
        virtual void printData() const override;

        /**
         * @brief Returns the enum type of the Teacher.
         *
         * @return User type.
         */
        virtual TYPE getType() const override;

};