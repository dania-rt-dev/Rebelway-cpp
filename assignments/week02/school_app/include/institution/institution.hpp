/**
 * @file institution.hpp
 *
 * @brief Defines the abstract Institution class.
 */

#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "../user/user.hpp"


/**
 * @class Institution
 *
 * @brief Abstract base class for an Institution.
 */
class Institution
{
    protected:
        std::string m_name{};
        std::string m_country{};
        std::string m_city{};

        std::vector<std::string> m_subjects{};
        std::unordered_map<std::string, User*> m_userMap{};
        std::unordered_map<User::TYPE, std::vector<std::string>> m_typeMap{};

    public:

        /**
         * @brief Constructor for the class.
         *
         * @param name Institution name.
         * @param country Institution country.
         * @param city Institution city.
         * @param userMap Unordered map of Users. <string, User*>.
         */
        Institution(std::string name, std::string country, std::string city, std::unordered_map<std::string, User*> userMap);

        /**
         * @brief Destructor.
         */
        virtual ~Institution() = default;

        /**
         * @brief Prints the full information of the Institution class.
         */
        virtual void printData() const;

        /**
         * @brief Returns the name.
         *
         * @return String value for name.
         */
        virtual std::string getName() const;

        /**
         * @brief Sets the name.
         *
         * @param name String value for the name.
         */
        virtual void setName(std::string name);

        /**
         * @brief Returns the country.
         *
         * @return String value for country.
         */
        virtual std::string getCountry() const;

        /**
         * @brief Sets the country.
         *
         * @param country String value for the country.
         */
        virtual void setCountry(std::string country);

        /**
         * @brief Returns the city.
         *
         * @return String value for city.
         */
        virtual std::string getCity() const;

        /**
         * @brief Sets the city.
         *
         * @param city String value for the city.
         */
        virtual void setCity(std::string city);

        /**
         * @brief Adds an User to the map.
         *
         * @param userName String to use as key for the User.
         * @param user Pointer to a user object.
         */
        virtual void addUser(const std::string& userName, User* user);

        /**
         * @brief Removes an User from the map.
         *
         * @param userName String key to represent the User.
         */
        virtual void removeUser(const std::string& userName);

        /**
         * @brief Searches for a User in the map.
         *
         * @param userName String to use as key for the User.
         *
         * @return Iterator to the position of the element if found. Iterator to end if not.
         */
        virtual std::unordered_map<std::string, User*>::const_iterator findUser(const std::string& userName) const;

        /**
         * @brief Prints the information of a given user.
         *
         * @param userName String to use as key for the user.
         */
        virtual void printUserData(const std::string& userName) const;

        /**
         * @brief Prints the list of users in the map.
         *
         * This function only prints the name keys.
         */
        virtual void printUserList() const;

        /**
         * @brief Prints the full information of the users in the map.
         */
        virtual void printAllUserData() const;

        /**
         * @brief Prints the full information of the users of the given type.
         *
         * @param type User enum type
         */
        virtual void printUsersByType(const User::TYPE type) const;
};