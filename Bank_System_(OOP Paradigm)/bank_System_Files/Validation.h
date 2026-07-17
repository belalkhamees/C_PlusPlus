#pragma once
#include <iostream>
#include <string>
using namespace std;

class Validation {
public:

    static bool validate_name(const string& name) {
        if (name.length() < 3 || name.length() > 20)
            return false;
        for (char c : name)
            if (!isalpha(c) && c != ' ')
                return false;
        return true;
    }

    static bool validate_password(const string& password) {
        if (password.length() < 8 || password.length() > 20) return false;
        for (char c : password)
            if (c == ' ') return false;
        return true;
    }

    static bool validate_balance(double balance) {
        return balance >= 1500;
    }

    static bool validate_salary(double salary) {
        return salary >= 5000;
    }

    static bool validate_withdraw(double amount, double balance) {
        return (amount > 0 && amount <= balance);
    }

            
    };




    