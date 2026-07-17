#pragma once
#define _HAS_STD_BYTE 0
#include "DataSourseInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:

	static void addClient(const Client& obj) {
		FilesHelper::saveClient(obj);
	}

	static void addEmployee(const Employee& obj) {
		FilesHelper::saveEmployee(obj);
	}

	static void addAdmin(const Admin& obj) {
		FilesHelper::saveAdmin(obj);
	}
	//------------------------------------------
	static void getAllClients() {
		FilesHelper::getClients();
	}

	static void getAllEmployees() {
		FilesHelper::getEmployees();
	}

	static void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	//------------------------------------------
	static void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "ClientsLastId.txt");
	}

	static void removeAllEmployees() {
		FilesHelper::clearFile("Employees.txt", "EmployeesLastId.txt");
	}

	static void removeAllAdmins() {
		FilesHelper::clearFile("Admins.txt", "AdminsLastId.txt");
	}
	//------------------------------------------

	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
	static void updateClients() {
		removeAllClients();
		for(auto& client : DataStorage::getAllClients())
		 addClient(*client);
	}
	static void updateEmployees() {
		removeAllEmployees();
		for (auto& employee : DataStorage::getAllEmployees())
			addEmployee(*employee);
	}
	static void updateAdmins() {
		removeAllAdmins();
		for (auto& admin : DataStorage::getAllAdmins())
			addAdmin(*admin);
	}
	
};




