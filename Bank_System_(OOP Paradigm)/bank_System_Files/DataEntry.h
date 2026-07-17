#pragma once
#include "Validation.h"
#include <string>
#include <iostream>
#include <limits>

class DataEntry
{
public:

    static std::string enterName() {
        std::string name;
        std::cin.ignore(1000, '\n');
        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        while (!Validation::validate_name(name)) {
            std::cout << "Invalid name!\n";
            std::cout << "Name must be 3 to 20 alphabetic characters (spaces allowed).\n";
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
        }

        return name;
    }

    static std::string enterPassword() {
        std::string password;
        std::cout << "Enter password: ";
        std::cin >> password;

        while (!Validation::validate_password(password)) {
            std::cout << "Invalid password!\n";
            std::cout << "Password must be 8 to 20 characters.\n";
            std::cout << "Enter password: ";
            std::cin >> password;
        }

        return password;
    }

    static double enterBalance() {
        double balance;
        std::cout << "Enter Balance: ";
        std::cin >> balance;

        while (!Validation::validate_balance(balance)) {
            std::cout << "Invalid Balance!\n";
            std::cout << "Minimum Balance is 1500\n";
            std::cout << "Enter Balance: ";
            std::cin >> balance;
        }

        return balance;
    }
  
    static double enterSalary() {
        double salary;
        std::cout << "Enter Salary: ";
        std::cin >> salary;

        while (!Validation::validate_salary(salary)) {
            std::cout << "Invalid Salary!\n";
            std::cout << "Minimum Salary is 5000\n";
            std::cout << "Enter Salary: ";
            std::cin >> salary;
        }
        return salary;
    }


};

