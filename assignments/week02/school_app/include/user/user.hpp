/**
 * @file user.hpp
 *
 * @brief Defines the abstract User class.
 */
#pragma once

#include <cstddef>
#include <string>

/**
* @brief Enum structure for diferent user types.
*/
enum class UserType
{
    NONE,       ///< UserType 0
    TEACHER,    ///< UserType 1
    STUDENT     ///< UserType 2
};

/**
 * @class User
 *
 * @brief Abstract base class for an User.
 */
class User
{
    protected:
        struct BirthDate
        {
            int m_year{};
            int m_month{};
            int m_day{};
        };

        size_t m_id{};

        std::string m_firstName{};
        std::string m_secondName{};

        BirthDate m_birthDate{};

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
        User(size_t id, std::string firstName, std::string secondName, int year, int month, int day);

        /**
         * @brief Destructor.
         */
        virtual ~User() = default;

        /**
         * @brief Prints the full information of the User class.
         */
        virtual void printData() const = 0;

        /**
         * @brief Returns the id value.
         *
         * @return Numeric value for id.
         */
        virtual size_t getID() const;

        /**
         * @brief Returns the enum userType of the User.
         *
         * @return Enum User userType.
         */
        virtual UserType getType() const = 0;

        /**
         * @brief Returns the first name of the user.
         *
         * @return String value for first name.
         */
        virtual std::string getFirstName() const;

        /**
         * @brief Sets the first name for the User.
         *
         * @param firstName String value for the first name.
         */
        virtual void setFirstName(const std::string& firstName);

        /**
         * @brief Returns the second name of the user.
         *
         * @return String value for second name.
         */
        virtual std::string getSecondName() const;

        /**
         * @brief Sets the second name for the User.
         *
         * @param secondName String value for the second name.
         */
        virtual void setSecondName(const std::string& secondName);

        /**
         * @brief Returns the user birth date.
         *
         * The value is returned in string format.
         *
         * @return String form for birth date.
         */
        virtual std::string getBirthDate() const;

        /**
         * @brief Sets the birth date of the User.
         *
         * @param year Numeric value for birth year.
         * @param month Numeric value for birth month.
         * @param day Numeric value for birth day.
         */
        virtual void setBirthDate(int year, int month, int day);

        /**
         * @brief Converts an enum value to a string.
         *
         * @param userType Enum value to process.
         *
         * @return String representing the enum.
         */
        static std::string enumToString(UserType userType);
};