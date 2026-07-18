# 🏦 Bank Management System (C++)

A console-based **Bank Management System** developed in **C++** as a course project to practice Object-Oriented Programming (OOP), file handling, and software design.

The application simulates a banking environment with three user roles: **Admin**, **Employee**, and **Client**, each with its own permissions and operations. Data is stored in text files to maintain persistence between program executions.

---

## ✨ Features

### 👤 Authentication

* Secure login system
* Role-based access (Admin, Employee, Client)

### 👨‍💼 Admin

* Manage employees
* Manage clients
* View and update personal information

### 👨‍💻 Employee

* Manage clients
* View salary
* Update personal information

### 👤 Client

* View account information
* Deposit and withdraw money
* Transfer money
* Update password

---

## 🛠️ Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL
* File Handling (`fstream`)
* Windows Console Application

---

## 📚 OOP Concepts

This project demonstrates the use of:

* Encapsulation
* Inheritance
* Abstraction
* Polymorphism
* Interfaces (Abstract Classes)
* Static Members

---

## 📂 Project Structure

```text
BankSystem
│
├── Core Classes
│   ├── Person
│   ├── Client
│   ├── Employee
│   └── Admin
│
├── Managers
│   ├── ClientManager
│   ├── EmployeeManager
│   └── AdminManager
│
├── Utilities
│   ├── Validation
│   ├── DataEntry
│   ├── Parser
│   └── DataStorage
│
├── File Handling
│   ├── FilesHelper
│   ├── FileManager
│   └── DataSourceInterface
│
├── Screens
│
└── Main
```
---

## 💾 Data Persistence

The system stores all data in text files and automatically loads and saves changes during program execution.

---

## 🎯 What I Learned

Through this project, I gained practical experience with:

* Designing applications using OOP principles
* Building a multi-class project with clear responsibilities
* File handling and data persistence
* Dynamic memory management
* Creating a menu-driven console application

---

## 🚀 Future Improvements

* Replace raw pointers with smart pointers
* Use a database instead of text files
* Improve security with password hashing
* Add transaction history
* Develop a GUI version

---

## 👨‍💻 Author

**Belal Khamees**

