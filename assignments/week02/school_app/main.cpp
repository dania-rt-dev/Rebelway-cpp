/**
 * @file main.cpp
 *
 * @brief Practice implementation of OOP school and student classes.
 *
 */

#include <iostream>
#include <unordered_map>

#include "include/institution/institution.hpp"
#include "include/user/user.hpp"
#include "include/user/student.hpp"
#include "include/user/teacher.hpp"

int main()
{
    int id = 102;
    std::string name = "Mark";
    std::string secondName = "Smith";
    int year = 1930;
    int month = 6;
    int day = 25;

    Student newStudent = Student(id, name, secondName, year, month, day);

    id = 10;
    name = "John";
    secondName = "Johnson";
    year = 1890;
    month = 5;
    day = 12;

    Teacher newTeacher = Teacher(id, name, secondName, year, month, day);

    std::string instName = "RacoonFord";
    std::string instCountry = "FakeCountryA";
    std::string instCity = "FakeCityA";
    std::unordered_map<std::string, User*> userMap {{"Mark", &newStudent}, {"John", &newTeacher}};

    Institution newInstitution = Institution(instName, instCountry, instCity, userMap);
    
    id = 110;
    name = "Johnanna";
    secondName = "Loop";
    year = 1990;
    month = 10;
    day = 15;
    Teacher newTeacher2 = Teacher(id, name, secondName, year, month, day);

    newInstitution.addUser("Johanna", &newTeacher2);    ///< Add test
    newInstitution.addUser("Johanna", &newTeacher2);    ///< Add repeated value test
    newInstitution.removeUser("Charles");                    ///< Remove not exisintg value test

    std::cout << "STUDENT PRINT TEST ---------------------------------------------------\n";
    newStudent.printData();
    std::cout << "TEACHER PRINT TEST ---------------------------------------------------\n";
    newTeacher.printData();
    std::cout << "INSTITUTION PRINT TEST ---------------------------------------------------\n";
    newInstitution.printData();
    std::cout << "----------------------\n";
    newInstitution.printUserList();
    std::cout << "----------------------\n";
    newInstitution.printAllUserData();
    std::cout << "----------------------\n";
    std::cout << "PRINT BY TYPE STUDENT ----------------------\n";
    newInstitution.printUsersByType(User::TYPE::STUDENT);
    std::cout << "PRINT BY TYPE TEACHER ----------------------\n";
    newInstitution.printUsersByType(User::TYPE::TEACHER);
    std::cout << "----------------------\n";
    newInstitution.removeUser("Mark");  ///< Remove exisitng value test (student).
    newInstitution.removeUser("Mark");  ///< Remove previously exisintg calue test.
    newInstitution.removeUser("John");  ///< Remove existing value test (teacher).
    std::cout << "PRINT BY TYPE STUDENT ----------------------\n";
    newInstitution.printUsersByType(User::TYPE::STUDENT);
    std::cout << "PRINT BY TYPE TEACHER ----------------------\n";
    newInstitution.printUsersByType(User::TYPE::TEACHER);

    return 0;
}