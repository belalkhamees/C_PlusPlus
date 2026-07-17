#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class DataSourceInterface
{

public:
	virtual void addClient(const Client& obj) = 0;
	virtual void addEmployee(const Employee& obj) = 0;
	virtual void addAdmin(const Admin& obj) = 0;

	virtual void getAllClients() = 0;
	virtual void getAllEmployees() = 0;
	virtual void getAllAdmins() = 0;

	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};

//Abstract class it will be implemented in FileManager class
//purpose -> add objects to files
