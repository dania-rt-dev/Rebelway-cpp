#include "../../include/institution/institution.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

Institution::Institution
    (
        std::string name,
        std::string country,
        std::string city,
        std::unordered_map<std::string, User*> userMap
    )
    :
    m_name(std::move(name)),
    m_country(std::move(country)),
    m_city(std::move(city))
    //m_userMap(std::move(m_userMap))
{
    for(auto iter = userMap.begin(); iter != userMap.end(); iter++)
    {
        addUser(iter->first, iter->second);
    }
}

void Institution::printData() const
{
    std::cout << m_name << ", " << m_city << ", " << m_country << "\n";
}

std::string Institution::getName() const
{
    return m_name;
}
void Institution::setName(std::string name)
{
    m_name = std::move(name);
}

std::string Institution::getCountry() const
{
    return m_country;
}
void Institution::setCountry(std::string country)
{
    m_country = std::move(country);
}

std::string Institution::getCity() const
{
    return m_city;
}
void Institution::setCity(std::string city)
{
    m_city = std::move(city);
}

void Institution::addUser(const std::string& userName, User* user)
{
    if(m_userMap.find(userName) == m_userMap.end())
    {
        m_userMap[userName] = user;
        m_typeMap[user->getType()].push_back(userName);

        std::cout << "User " << userName << " added to the database.\n";
    }
    else
    {
        std::cout << "User " << userName << " is already in the database.\n";
    }
}

void Institution::removeUser(const std::string& userName)
{
    auto iter = findUser(userName);
    if(iter != m_userMap.end())
    {
        auto& auxVector = m_typeMap[iter->second->getType()];
        auxVector.erase(std::remove(auxVector.begin(), auxVector.end(), userName), auxVector.end());
        m_userMap.erase(userName);       
        std::cout << "User " << userName << " has been removed from the database.\n";
    }
    else
    {
        std::cout << "User " << userName << " could not be found.\n";
    }
}

std::unordered_map<std::string, User*>::const_iterator Institution::findUser(const std::string& userName) const
{
    auto iter = m_userMap.find(userName);
    if(iter != m_userMap.end())
    {
        std::cout << "User " << userName << " is in the database.\n";
    }
    else
    {
        std::cout << "User " << userName << " is not in the database.\n";
    }

    return iter;
}

void Institution::printUserData(const std::string& userName) const
{
    auto iter = m_userMap.find(userName);
    if(iter != m_userMap.end())
    {
        iter->second->printData();
        switch(iter->second->getType())
        {
            case UserType::STUDENT:
                std::cout << "They are a student\n";
                break;
            case UserType::TEACHER:
                std::cout << "They are a teacher\n";
                break;
            default:
                break;
        }
    }
    else
    {
        std::cout << "User " << userName << " could not be found.\n";
    }
}
void Institution::printUserList() const
{
    for(auto iter = m_userMap.begin(); iter != m_userMap.end(); iter++)
    {
        std::cout << iter->first << "\n";
    }
}

void Institution::printAllUserData() const
{
    for(auto iter = m_userMap.begin(); iter != m_userMap.end(); iter++)
    {
        printUserData(iter->first);
        std::cout << "---------------------------------------------------\n";
    }
}

void Institution::printUsersByType(const UserType userType) const
{  
    auto mainIter = m_typeMap.find(userType);
    if(mainIter == m_typeMap.end() || mainIter->second.empty())
    {
        std::cout << "There are not " << User::enumToString(userType) << " in the map\n";
        return;
    }
    else
    {
        for(auto iter = mainIter->second.begin(); iter != mainIter->second.end(); iter++)
        {
            printUserData(*iter);
        }
    }
}