#pragma once
#include <vector>
#include <memory>


using namespace std;


//forward declaration
// Assuming these classes are defined elsewhere
class Admin;
class Employee;
class Client;

class DataStorage {
private:

    static vector<Client*> allClients;
    static vector<Employee*> allEmployees;
    static vector<Admin*> allAdmins;


public:
    // Clients
    static void setAllClients(Client* client) {
        allClients.push_back(client);
    }

    static vector<Client*>& getAllClients() {
        return allClients;
    }


    // Employees
    static void setAllEmployees(Employee* employee) {
        allEmployees.push_back(employee);
    }

    static vector<Employee*>& getAllEmployees() {
        return allEmployees;
    }

    
    // Admins
    static void setAllAdmins(Admin* admin) {
        allAdmins.push_back(admin);
    }

    static vector<Admin*>& getAllAdmins() {
        return allAdmins;
    }


    //clear objects in heap holded by pointers in vectors
    static void clearHeap() {
       
        for (auto client : allClients) {
            delete client;
        }
        allClients.clear();

        for (auto employee : allEmployees) { 
            delete employee;
        }
        allEmployees.clear(); 

        for (auto admin : allAdmins) {
            delete admin;
        }
        allAdmins.clear();

    }

};




