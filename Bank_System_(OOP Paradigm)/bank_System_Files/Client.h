#pragma once
#include "Person.h"
#include <vector>

class Client : public Person
{
private:
    double balance{};

public:
    Client(int id, const string& name, const string& password, double balance) 
    : Person(id,name, password) {
        set_balance(balance);
    }

    //static vector<Client> allClients;

    //static vector<Client>& getAllClients() {
    //    return allClients;
    //}

    void set_balance(double balance) {
        if (Validation::validate_balance(balance)) {
            this->balance = balance;
        }
        else {
            cout << "invalid Balance: Minimum Balance is 1500\n";
        }
    }

    //double get_balance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            //cout << "Your Transaction accepted.\n";
        }
        else {
            cout << "invalid amount\n";
        }
    }

    void withdraw(double amount) {
        if (Validation::validate_withdraw(amount, balance)) {
            balance -= amount;
            //cout << "Your Transaction accepted.\n";
        }
        else {
            cout << "invalid amount\n";
        }
    }

    void transfer_to(double amount, Client& recipient) {
        if (Validation::validate_withdraw(amount, balance)) {
            this->withdraw(amount);
            recipient.deposit(amount);
            //cout << "Your Transaction accepted.\n";
        }
        else {
            cout << "invalid amount\n";
        }
    }

    double check_balance() const { return balance; }

    
    string get_info() {
        return   //"\n--------- Client info ---------\n" +
             Person::get_info() +
            "Balance: " + to_string_deluxe(balance) + " $" + "\n"
            "---------------------------------\n";
    }
};


