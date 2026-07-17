#pragma once
#define _HAS_STD_BYTE 0
#include "EmployeeManager.h"
#include "ClientManager.h"
#include "Admin.h"


class AdminManager : EmployeeManager
{

public:
	
	static Admin* login(int id, const string& password) {
		for (auto& admin : DataStorage::getAllAdmins()) {
			if (admin->get_id() == id && admin->get_password() == password) {
				return admin; 
			}
		}
		return nullptr; // not found
	}

	static void updatePassword(Admin* admin) {
		admin->set_password(DataEntry::enterPassword());
		cout << "\nPassword Updated Successfully.\n";
	}

	static void newEmployee(Admin* admin) {
		int id = FilesHelper::getLast("EmployeesLastId.txt");
		id++;
		string name = DataEntry::enterName();
		string password = DataEntry::enterPassword();
		double salary = DataEntry::enterSalary();

		Employee* employee = new Employee(id, name, password, salary);
		
		admin->addEmployee(employee);
		FileManager::updateEmployees();
	}

	static void searchForEmployee(Admin* admin) {
		cout << "Enter Employee Id Number: ";
		int id;  cin >> id;

		Employee* employee = admin->searchEmployee(id);
		if (employee) cout << employee->get_info();
		else {
			cout << "\Employee not found.\n";
		}
	}


	static void editEmployeeInfo(Admin* admin) {
		cout << "Enter Employee Id: ";
		int id;
		cin >> id;
		Employee* employee = Admin::searchEmployee(id);
		if (!employee) {
			cout << "\Employee Not Found.\n";
		}
		else {
			cout << "\n--------- Employee Old Data ---------\n";			
			cout << employee->get_info();
			cout << "--------- Employee New Data ---------\n";
			string name = DataEntry::enterName();
			string password = DataEntry::enterPassword();
			double salary = DataEntry::enterSalary();

			admin->editEmployee(id, name, password, salary);
				
			FileManager::updateEmployees();
			cout << "\nEmployee Info Updated Successfully.\n";
		}
	}

	static void printAdminMenu() {
		system("cls");
		cout << "--------- Admin Menu ---------" << endl;
		cout << "(1) Display my info" << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Add new Employee" << endl;
		cout << "(8) Search for Employee" << endl;
		cout << "(9) List all Employees" << endl;
		cout << "(10) Edit Employee info" << endl;
		cout << "(11) Logout\n" << endl;
	}

	static void back(Admin* admin) {
		cout << endl;
		system("pause");
		adminOptions(admin);
	}

	static bool adminOptions(Admin* admin) {
		printAdminMenu();
		cout << "Your choice is: ";
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			cout << admin->get_info();
			break;
		case 2:
			system("cls");
			updatePassword(admin);
			FileManager::updateAdmins();
			break;
		case 3:
			system("cls");
			EmployeeManager::newClient(admin);
			cout << "\nClient Added Successfully.\n";
			break;
		case 4:
			system("cls");
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			system("cls");
			EmployeeManager::listAllClients(admin);
			break;
		case 6:
			system("cls");
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			system("cls");
			newEmployee(admin);
			cout << "\nEmployee Added Successfully.\n";
			break;
		case 8:
			system("cls");
			searchForEmployee(admin);
			break;
		case 9:
			system("cls");
			cout << "--------- All Employees ---------\n\n";
			admin->listEmployee();
			break;
		case 10:
			system("cls");
			editEmployeeInfo(admin);
			break;
			
			
		case 11:
			return false;
			break;
		default:
			cout << "\nPlease Enter A Number Exists In The Menu!\n";
			Sleep(2500);
			system("cls");
			adminOptions(admin);
			return true;
		}
		
		back(admin);
		return true;
	}




};

