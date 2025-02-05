#include <iostream>
#include "boot.h"
#include "user.h"

using namespace std;

int main() {
    systemBoot();

    int choice;
    bool isRunning = true;

    while (isRunning) {
        // If no user is logged in
        while (currentUser.empty() && isRunning) {
            cout << "\n--- Welcome Menu ---" << endl;
            cout << "1. Create Account" << endl;
            cout << "2. Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    if (createAccount()) {
                        // Automatically log in the user after account creation
                        currentUser = username;  // Set currentUser
                        cout << "Account created successfully! Welcome, " << currentUser << "!" << endl;
                    }
                break;
                case 2:
                    login();
                break;
                case 3:
                    isRunning = false;
                break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }

        // If a user is logged in
        while (!currentUser.empty() && isRunning) {
            cout << "--- User Menu ---" << endl;
            cout << "1. Logout" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    logout();
                break;
                case 2:
                    isRunning = false;
                break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    cout << "Program terminated." << endl;
    return 0;
}