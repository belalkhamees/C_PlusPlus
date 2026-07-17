#pragma once
#include "Employee.h"

class Admin : public Employee
{
public:

    Admin(int id, const string& name, const string& password, double salary)
        : Employee(id, name, password, salary) 
    {   
    }

    //static vector<Admin> allAdmins;

    //static vector<Admin>& getAllAdmins() {
    //    return allAdmins;
    //}


    //-------------------------------------------
    void addEmployee(Employee* employee) {
        DataStorage::setAllEmployees(employee);
    }

    static Employee* searchEmployee(int id) {
        for (auto& employee : DataStorage::getAllEmployees()) {
            if (employee->get_id() == id) {
                return employee; 
            }
        }
        return nullptr; // not found
    }

    void editEmployee(int id, string name, string password, double salary) {
        Employee* employee = searchEmployee(id);
            employee->set_name(name);
            employee->set_password(password);
            employee->set_salary(salary);
       
    }

    void listEmployee() {
        for (auto& employee : DataStorage::getAllEmployees()) {
            cout << employee->get_info() << endl ;
        }
    }

    string get_info()  {
        return "\n--------- Admin info ---------\n"
            + Person::get_info() +
            "Salary: " + to_string_deluxe(check_salary()) + " $" + "\n"
            "---------------------------------\n";
    }
};

