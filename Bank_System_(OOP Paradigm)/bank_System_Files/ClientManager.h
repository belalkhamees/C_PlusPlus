#pragma once
#define _HAS_STD_BYTE 0
#include "Client.h"
#include "DataEntry.h"
#include "Employee.h"

#include <string>

class ClientManager 
{
public:

	static Client* login(int id, const string& password) {
        Client* client = Employee::searchClient(id);
        if (client && client->get_password() == password) {
            return client;
        }
           
       return nullptr;
	}

    static std::string enterNewPassword() {
        std::string password;
        std::cout << "\nEnter Your New Password: ";
        std::cin >> password;

        while (!Validation::validate_password(password)) {
            std::cout << "Invalid Password!\n";
            std::cout << "Password must be 8 to 20 characters.\n";
            std::cout << "Please Enter a valid Password: ";
            std::cin >> password;
        }

        return password;
    }

    static void updatePassword(Person* person) {
        person->set_password(enterNewPassword());
        cout << "\nPassword Updated Successfully.\n";
    }

    static void back(Client* client) {
        cout << endl;
        system("pause");
        clientOptions(client);
    }

    static void printClientMenu() {
        system("cls"); 
        cout << "--------- Client Menu ---------" << endl;
        cout << "(1) Display my info" << endl;
        cout << "(2) Check balance" << endl;
        cout << "(3) Update Password" << endl;
        cout << "(4) Withdraw" << endl;
        cout << "(5) Deposit" << endl;
        cout << "(6) Transfer amount" << endl;
        cout << "(7) Logout\n" << endl;
    }


    static bool clientOptions(Client* client) {
        printClientMenu();
        cout << "Your choice is: ";
       
        double amount;
        int choice, id;
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            cout << client->get_info();
            break;

        case 2:
            system("cls");
            cout << "Your Balance Is: " << client->check_balance() << " $" << endl;
            break;

        case 3:
            system("cls");
            updatePassword(client);
            FileManager::updateClients();
            break;

        case 4:
            system("cls");
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            client->withdraw(amount);
            FileManager::updateClients();
            cout << "\nTransaction Approved!\n";
            break;

        case 5:
            system("cls");
            cout << "Enter amount to deposit: ";
            cin >> amount;
            client->deposit(amount);
            FileManager::updateClients();
            cout << "\nTransaction Approved!\n";
            break;

        case 6:
            system("cls");
            cout << "Enter Id Of The Recipient: ";
            cin >> id;
            while (!Employee::searchClient(id)) {
                system("cls");
                cout << "Invalid Id.\n";
                cout << "\nEnter Recipient id: ";
                cin >> id;
            }
            cout << "\nEnter Amount To Transfer: ";
            cin >> amount;
            client->transfer_to(amount, *Employee::searchClient(id));
            FileManager::updateClients();
            cout << "\nTransaction Approved!\n";
            break;

        case 7:
            return false;
            break;
        default:
            cout << "\nPlease Enter A Number Exists In The Menu!\n";
            Sleep(2500);
            system("cls");
            clientOptions(client);
            return true;
        }
        back(client);
        return true;
    }

};


  


