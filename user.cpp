#include <iostream>
#include <fstream>
#include <string>
#include "user.h"

using namespace std;

string currentUser = "";
string username = "";

// function to create an account and save it to users.txt file as a database
bool createAccount() {
    string password;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        return true;
    } else {
        cout << "Unable to open file." << endl;
        return false;
    }
}

// function to log in
bool login() {
    string inputUsername, inputPassword, fileUsername, filePassword;
    cout << "Enter username: ";
    cin >> inputUsername;
    cout << "Enter password: ";
    cin >> inputPassword;

    // function to check if the credentials match the stored accounts
    ifstream file("users.txt");
    if (file.is_open()) {
        while (file >> fileUsername >> filePassword) {
            if (inputUsername == fileUsername && inputPassword == filePassword) {
                currentUser = inputUsername;
                cout << "Login successful! Welcome, " << currentUser << "!" << endl;
                file.close();
                return true;
            }
        }
        file.close();
        cout << "Invalid username or password." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
    return false;
}

void logout() {
    cout << "User " << currentUser << " has logged out." << endl;
    currentUser = "";
}