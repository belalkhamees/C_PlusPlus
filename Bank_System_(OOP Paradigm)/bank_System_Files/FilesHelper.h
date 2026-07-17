#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "Parser.h"


class FilesHelper
{
public:
	//remove last id - add new id
	static void saveLast(const string& fileName, int id) {
		fstream file(fileName, ios::out);
		file << id;
		file.close();
	}

	//open last id file - take id number - return id
	static int getLast(const string& fileName) {
		fstream file(fileName, ios::in);
		string id;
		getline(file, id);
		file.close();
		int last_id = stoi(id);
		return last_id;
	}

	// add client to clients file 
	static void saveClient(const Client& c) {

	fstream file("Clients.txt", ios::app);
	int id = getLast("ClientsLastId.txt");  // read last id client

	file << ++id << "|" << c.get_name() << "|" << c.get_password() << "|" << c.check_balance() << endl;
	file.close();
	saveLast("ClientsLastId.txt", id);   //add new last id to client id file 
	}

	// add Employee to Employees file 
	static void saveEmployee(const Employee& e) {

		fstream file("Employees.txt", ios::app);
		int id = getLast("EmployeesLastId.txt");  // read last id Employee

		file << ++id << "|" << e.get_name() << "|" << e.get_password() << "|" << e.check_salary() << endl;
		file.close();
		saveLast("EmployeesLastId.txt", id);   //add new last id to Employee id file 
	}

	// add Admin to Admins file 
	static void saveAdmin(const Admin& a) {

		fstream file("Admins.txt", ios::app);
		int id = getLast("AdminsLastId.txt");  // read last id Admin

		file << ++id << "|" << a.get_name() << "|" << a.get_password() << "|" << a.check_salary() << endl;
		file.close();
		saveLast("AdminsLastId.txt", id);   //add new last id to Admin id file 
	}

	//-----------------------------------------
	
	//get clients from file to vector 
	static void getClients() {
		//Client::allClients.clear();

		string line;
		fstream file("Clients.txt", ios::in);
		while (getline(file, line)) {
			Client* c = Parser::parseToClient(line);
			DataStorage::setAllClients(c);
		}
		file.close();

	}

	//get Employees from file to vector 
	static void getEmployees() {
		//Employee::allEmployees.clear();

		string line;
		fstream file("Employees.txt", ios::in);
		while (getline(file, line)) {
			Employee* e = Parser::parseToEmployee(line);
			DataStorage::setAllEmployees(e);
		}
		file.close();

	}

	//get Admins from file to vector 
	static void getAdmins() {
		//Admin::allAdmins.clear();

		string line;
		//fstream file("Admins.txt", ios::in);
		fstream file("Admins.txt", ios::in);

		while (getline(file, line)) {
			Admin* a = Parser::parseToAdmin(line);
			DataStorage::setAllAdmins(a);
		}
		file.close();
	}

	
	

	static void clearFile(string fileName, string lastIdFile) {
		fstream file1(fileName, ios::out);
		file1.close();

		fstream file2(lastIdFile, ios::out);
		file2 << 0;
		file2.close();

	}
	

};

