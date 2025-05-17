/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("database/" + username + ".txt");
    if (file.is_open()) {
        file << username << endl << password;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error creating user file.\n";
    }
}

// Function to login an existing user
void loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("database/" + username + ".txt");
    if (file.is_open()) {
        getline(file, storedUsername);
        getline(file, storedPassword);
        file.close();

        if (username == storedUsername && password == storedPassword) {
            cout << "Login successful!\n";
        } else {
            cout << "Invalid credentials.\n";
        }
    } else {
        cout << "User not found.\n";
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid option.\n";
    }

    return 0;
}
