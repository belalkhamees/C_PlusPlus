#pragma once
#define _HAS_STD_BYTE 0
#include "Employee.h"
#include "FilesHelper.h"
#include "DataEntry.h"
#include "FileManager.h"
#include <windows.h>

class EmployeeManager
{
public:

	static Employee* searchEmployee(int id) {
		for (auto& employee : DataStorage::getAllEmployees()) {
			if (employee->get_id() == id) {
				return employee; 
			}
		}
		return nullptr; // not found
	}

	static Employee* login(int id, const string& password) {
		Employee* employee = searchEmployee(id);
		if (employee && employee->get_password() == password) {
			return employee;
		}

		return nullptr;
	}

	static void back(Employee* employee) {
		cout << endl;
		system("pause");
		employeeOptions(employee);
	}

	static void newClient(Employee* employee) {
		int id = FilesHelper::getLast("ClientsLastId.txt");
		++id;
		string name = DataEntry::enterName();
		string password = DataEntry::enterPassword();
		double balance = DataEntry::enterBalance();

		Client* client = new Client (id, name, password, balance);

		employee -> addClient(client);
		FileManager::updateClients();
	}

	static void searchForClient(Employee* employee) {
		cout << "Enter Client Id Number: ";
		int id;  cin >> id;

		Client* client = Employee::searchClient(id);
		if (client) cout << client -> get_info();
		else {
			cout << "\nClient Not Found!\n";
		}
	}

	static void updatePassword(Employee* employee) {
		employee->set_password(DataEntry::enterPassword());
		cout << "\nPassword Updated Successfully.\n";

	}

	static void editClientInfo(Employee* employee) {		
		cout << "Enter Client Id: ";
		int id;
		cin >> id;
		Client* client = Employee::searchClient(id);
		if (!client) {
		cout << "\nClient Not Found!\n";
		}
		else {		
			cout << "\n--------- Client Old Data ---------\n";			
			cout << client->get_info();
			cout << "--------- Client New Data ---------\n";
			string name = DataEntry::enterName();
			string password = DataEntry::enterPassword();
			double balance = DataEntry::enterBalance();

			employee->editClient(
				id,
				name,
				password,
				balance);

			FileManager::updateClients();
			cout << "\nClient Info Updated Successfully.\n";
		}

	}

	static void listAllClients(Employee* employee) {
		cout << "--------- All Clients ---------\n" << endl;
	          employee->listClient();
	}

	static void printEmployeeMenu() {
		system("cls");
		cout << "--------- Employee Menu ---------" << endl;
		cout << "(1) Display my info" << endl;
		cout << "(2) Check salary" << endl;
		cout << "(3) Update Password" << endl;
		cout << "(4) Add new client" << endl;
		cout << "(5) Search for client" << endl;
		cout << "(6) List all clients" << endl;
		cout << "(7) Edit client info" << endl;
		cout << "(8) Logout\n" << endl;
	}

	static bool employeeOptions(Employee* employee) {
		printEmployeeMenu();
		cout << "Your choice is: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			cout << employee->get_info();
			break;
		case 2:
			system("cls");
			cout << "Your Salary Is: " << employee->check_salary() << " $" << endl;
			break;
		case 3:
			system("cls");
			updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 4:
			system("cls");
			newClient(employee);
			break;
		case 5:
			system("cls");
			searchForClient(employee);
			break;
		case 6:
			system("cls");
			listAllClients(employee);
			break;
		case 7:
			system("cls");
			editClientInfo(employee);
			break;
		case 8:
			return false;
			break;
		default:
			cout << "\nPlease Enter A Number Exists In The Menu!\n";
			Sleep(2500);
			system("cls");
			employeeOptions(employee);
			return true;
		}
		back(employee);
		return true;
	}
};




