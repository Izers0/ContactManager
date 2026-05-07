#include "contactFunctionHeader.h"
#include <iostream>
#include <fstream>
#include "contactClass.h"
using namespace std;

void menu() {

    cout << "1. View Contacts\n";
    cout << "2. Add a New Contact\n";
    cout << "3. Edit an Existing Contact\n";
    cout << "4. Exit\n\n";
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

void editContact() {}

Contact addContact() {

    // ask for first name input
    string enterFirstName;
    do {
        cout << "Enter contacts first name: ";

        getline(cin, enterFirstName);
    } while (enterFirstName.empty());


    // ask for last name input
    string enterLastName;
    do {
        cout << "Enter contact last name: ";
        getline(cin, enterLastName);
    } while (enterLastName.empty());

    // ask for phone number input
    int enterPhoneNumber;
    cout << "Enter contact phone number: ";
    while (!(cin >> enterPhoneNumber)) {

        cout << "Invalid input. Please try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    Contact newContact = Contact(enterFirstName, enterLastName, enterPhoneNumber);

    return newContact;
}