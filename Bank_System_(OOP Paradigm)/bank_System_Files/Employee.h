#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "DataStorage.h"

using namespace std;

    class Employee : public Person {
    private:
        double salary;

    public:

        Employee(int id, const string& name, const string& password, double salary)
            : Person(id, name, password){
            set_salary(salary);
        }

        //static vector<Employee> allEmployees;

        //static vector<Employee>& getAllEmployees() {
        //    return allEmployees;
        //}

         void addClient(Client* client) {
            DataStorage::setAllClients(client);
        }

       static Client* searchClient(int id) {
            for (auto& client : DataStorage::getAllClients()) {
                if (client->get_id() == id) {
                    return client; 
                }
            }
            return nullptr; // not found
        }

        void listClient() {
            for (auto& client : DataStorage::getAllClients()) {
                cout << client->get_info() << endl ;
            }
        }

        void editClient(int id, string name, string password, double balance) {
            Client* client = searchClient(id);
            client-> set_name(name);
            client->set_password(password);
            client->set_balance(balance);
            
            
        }

        

        void set_salary(double salary) {
            if (Validation::validate_salary(salary)) {
                this->salary = salary;
            }
            else {
                cout << "Invalid salary\n";
            }
        }

        double check_salary() const { return salary; }
       

        
        string get_info() {
            return //"\n--------- Employee info ---------\n" +
                 Person::get_info() +
                "Salary: " + to_string_deluxe(salary)  +" $" + "\n"
                "---------------------------------\n";
        }
    };










