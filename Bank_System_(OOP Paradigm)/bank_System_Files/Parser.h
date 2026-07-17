#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class Parser
{
private:
	static vector<string> split(const string& line) {
		stringstream ss(line);
		string part;

		vector<string> parts;

		while (getline(ss, part, '|')) {
			parts.push_back(part);
		}
		return parts;
	}

public:
	static Client* parseToClient(const string& line) {
		vector<string> parts = split(line);
		return new Client(
			stoi(parts[0]),
			     parts[1],
			     parts[2],
			stod(parts[3]));
	}

	static Employee* parseToEmployee(const string& line) {
		vector<string> parts = split(line);
		return new Employee(
			stoi(parts[0]),
			     parts[1],
			     parts[2],
			stod(parts[3]));
	}

	static Admin* parseToAdmin(const string& line) {
		vector<string> parts = split(line);
		return new Admin(
			stoi(parts[0]),
			     parts[1],
			     parts[2],
			stod(parts[3]));
	}

};

