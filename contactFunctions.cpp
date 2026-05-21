#include "contactFunctionHeader.h"
#include <iostream>
#include <fstream>
#include "contactClass.h"
#include <vector>
using namespace std;

bool isStringEmpty(string &userInput) {

    // if the string is empty show error and return false else return true
    if (userInput.empty()) {
        return false;
    }
    return true;
}

void stringLength (int limit, string &userInput) {

    // set limit of string
    int charLimit = limit;

    if (userInput.length() >= charLimit) {
        // No More Printing In Validation Code
    }
}


void writeContact() {

    ofstream contactFile;

    contactFile.open("savedContacts.txt", ios::app);

    if (contactFile.is_open()) {
        cout << "Contact file successfully opened \n\n";
    } else {
        cout << "Unable to open file \n";
    }

    Contact writeNewContact = addContact();

    contactFile << writeNewContact.getFirstName() << " " << writeNewContact.getLastName()
                << " " << writeNewContact.getPhoneNumber() << "\n";

    contactFile.close();
}

void displayContacts() {

    ifstream contactFile ("savedContacts.txt");

    // holds file contents
    string readFile;

    if (contactFile.is_open()) {
        cout << "Contact file successfully opened when trying to display \n\n";

        while (contactFile) {

            getline(contactFile, readFile);

            cout << readFile << "\n";
        }
    } else {
        cout << "Unable to open file when trying to display \n";
    }
}

void editContact() {

    fstream contactFile ("savedContacts.txt");

    vector <string> contacts;

    if (contactFile.is_open()) {
        string readFile;

        // temporarily store each line in the file in a vector
        while (getline(contactFile, readFile)) {
            contacts.push_back(readFile);
        }
        contactFile.close();
    }

    // loop through contacts and give each a number
    for (int i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". " << contacts[i] << "\n";
    }

    cout << "Which Contact do you wish to edit: ";

    // user chooses the index of the contact they want to change
    int userInput;
    cin >> userInput;

    string userEdit;
    cin >> userEdit;

    // Compare user choice to vector index
    cout << contacts[userInput - 1] << "\n";
    contacts[userInput - 1] = userEdit;


    /*
    for (int i = 0; i < contacts.size(); i++) {

        cout << i + 1 << ". " << contacts[userInput] << "\n";
    } */
}


void menu() {

    cout << "1. View Contacts\n";
    cout << "2. Add a New Contact\n";
    cout << "3. Edit an Existing Contact\n";
    cout << "4. Exit\n\n";
}


string getFirstName() {
    string enterFirstName;
    cout << "Enter contacts first name (char limit 15): ";

    do {
        getline(cin, enterFirstName);
        if (isStringEmpty(enterFirstName) == false) {
            cout << "Enter a valid First Name";
        }
    } while (isStringEmpty(enterFirstName) == false);
    return enterFirstName;
}

string getLastName() {
    string enterLastName;
    cout << "Enter contact last name (char limit: 20): ";

    do {
        getline(cin, enterLastName);
        if (isStringEmpty(enterLastName) == false) {
            cout << "Enter a valid Last Name";
        }
    } while (isStringEmpty(enterLastName) == false);
    return enterLastName;
}

string getPhoneNumber() {
    string enterPhoneNumber;
    cout << "Enter contact phone number: ";

    do {
        getline(cin, enterPhoneNumber);
        if (isStringEmpty(enterPhoneNumber) == false) {
            cout << "Enter a valid Phone Number";
        }
    } while (isStringEmpty(enterPhoneNumber) == false);
    return enterPhoneNumber;
}


Contact addContact() {

    Contact newContact = Contact(getFirstName(), getLastName(), getPhoneNumber());

    return newContact;
}