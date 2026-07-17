#pragma once
#define _HAS_STD_BYTE 0
#include "FileManager.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <thread>
#include <windows.h>
#include "AdminManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"

using namespace std;

class Screens
{
public:

static void bankName() {
	  cout << R"(

                                $$$$$$\  $$$$$$$\  $$\       $$$$$$\  $$\       
                                $$  __$$\ $$  __$$\ $$ |     $$  __$$\ $$ |      
                                $$ |  $$ |$$ |  $$ |$$ |     $$ /  $$ |$$ |      
                                $$$$$$$  |$$$$$$$\ |$$ |     $$$$$$$$ |$$ |      
                                $$  __$$< $$  __$$\ $$ |     $$  __$$ |$$ |      
                                $$ |  $$ |$$ |  $$ |$$ |     $$ |  $$ |$$ |      
                                $$$$$$$  |$$$$$$$  |$$$$$$$$\$$ |  $$ |$$$$$$$$\ 
                                \_______/ \_______/ \________|\__|  \__|\________|
                                
                                $$$$$$\   $$$$$$\  $$\   $$\ $$\   $$\ 
                                $$  __$$\ $$  __$$\ $$$\  $$ |$$ | $$  |
                                $$ |  $$ |$$ /  $$ |$$$$\ $$ |$$ |$$  / 
                                $$$$$$$\ |$$$$$$$$ |$$ $$\$$ |$$$$$  /  
                                $$  __$$\ $$  __$$ |$$ \$$$$ |$$  $$<   
                                $$ |  $$ |$$ |  $$ |$$ |\$$$ |$$ |\$$\  
                                $$$$$$$  |$$ |  $$ |$$ | \$$ |$$ | \$$\ 
                                \_______/ \__|  \__|\__|  \__|\__|  \__|

)";
	}
	 

static void welcome() {
        system("Color 0");

        cout << "\n\n\n\n\n\n";
        cout << "\t  ##      ##  #######  ##       #######  ########  ####    ####  #######    ########  ####### \n";
        cout << "\t  ##  #   ##  ##       ##       ##       ##    ##  ##  #  #  ##  ##            ##     ##   ## \n";
        cout << "\t  ## ###  ##  ######   ##       ##       ##    ##  ##   ##   ##  #######       ##     ##   ## \n";
        cout << "\t  ## ##   ##  ##       ##       ##       ##    ##  ##        ##  ##            ##     ##   ## \n";
        cout << "\t  ###    ###  #######  #######  #######  ########  ##        ##  #######       ##     ####### \n";

        bankName();

        Sleep(5000);
        system("cls");
        system("Color 7");
    }

static void logout() {
    system("cls");
    loginScreen(loginAs());
}

static void loginOptions() {

    cout << "\n--------- login Options ---------\n";

    cout << "(1) Admin " << endl;
    cout << "(2) Employee " << endl;
    cout << "(3) Client " << endl << endl;
    cout << "(4) End Program " << endl;
    cout << "---------------------------------\n";
}



static void invalid(int c) {
    system("cls");
    cout << "Incorrect id or password.\n" << endl;
    loginScreen(c);
}

static int loginAs() {
    loginOptions();
    int choice;

    while (!(cin >> choice)) {
        cout << "Invalid Choice. Please Enter a Number: ";

        cin.clear(); 
        cin.ignore(1000, '\n');
    }

    if (choice == 1 || choice == 2 || choice == 3) {
        system("cls");
        return choice;
    }
    else if (choice == 4) {
        system("cls");
        cout << "                                      ======================================\n";

        cout << "                                        THANK YOU FOR CHOOSING BELAL BANK!\n";

        cout << "                                      ======================================\n\n";
        DataStorage::clearHeap();
        exit(0);
    }
    else {
        cout << "Please Enter A Number Exists In The Menu!\n";
        Sleep(2500);
        system("cls");
        return loginAs();
    }
}


static void loginScreen(int choice) {

        int id;  string password;

        cout << "Enter id: ";

        while (!(cin >> id)) {
            cout << "Invalid ID. Please Enter a Number: ";

            cin.clear(); // Clear the error state
            cin.ignore(1000, '\n');
        }

        cout << "Enter password: ";
        cin >> password;

        switch (choice) {
        case 1: 
        {
            //Admin* admin = AdminManager::login(id, password);
            if (AdminManager::login(id, password) != NULL) {   //if admin (exists)
                while (AdminManager::adminOptions(AdminManager::login(id, password)) != false);
                logout();
            }
            else invalid(1);
            break;
        }
        
        case 2: 
        {
            //Employee* employee = EmployeeManager::login(id, password);
            if (EmployeeManager::login(id, password) != NULL) {   //if employee (exists)
                while (EmployeeManager::employeeOptions(EmployeeManager::login(id, password)) != false);
                logout();
            }
            else invalid(2);
            break;

        }
        case 3: 
        {
            //Client* client = ClientManager::login(id, password);
            if (ClientManager::login(id, password) != NULL) {   //if client (exists)
                while (ClientManager::clientOptions(ClientManager::login(id, password)) != false);
                logout();
            }
            else invalid(3);
            break;

        }
        default: {
            system("cls");
            loginOptions();
        }
            
        }

    }


    static void runApp() {
        FileManager::getAllData();
        welcome();
        loginScreen(loginAs());
    }

    
};


