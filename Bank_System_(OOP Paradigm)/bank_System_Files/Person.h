#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Validation.h"

class Person {
private:
    int    id;
    std::string name;
    std::string password;

public:

    Person(int id, const std::string& name, const std::string& password) {
        set_id(id);
        set_name(name);
        set_password(password);
    }

    void set_id(int id) { this -> id = id; }

    void set_name(const std::string& name) {
        if (Validation::validate_name(name)) {
            this->name = name;
        }
        else {
            throw std::invalid_argument("invalid Name");
        }
    }

    void set_password(const std::string& password) {
        if (Validation::validate_password(password)) {
            this->password = password;
        }
        else {
            throw std::invalid_argument("invalid password");
        }
    }


    int get_id() const { return id; }
    const std::string& get_name() const { return name; }
    const std::string& get_password() const { return password; }


    string to_string_deluxe(double num) {
        string s = to_string(num); // Standard to_string gives 6 decimal places by default

        // 1. Check if there is a decimal point
        if (s.find('.') != string::npos) {

            // 2. Remove all trailing zeros
            while (s.back() == '0') {
                s.pop_back();
            }

            // 3. If the last character is now the dot, remove it too
            if (s.back() == '.') {
                s.pop_back();
            }
        }

        return s;
    }
   

     std::string get_info() const {
     return  "ID:   " + std::to_string(id) + "\n"
             "Name: " + name + "\n" +
             "Password: " + get_password() + "\n";
    }

    
};