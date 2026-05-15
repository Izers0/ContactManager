#include "contactFunctionHeader.h"
#include <iostream>
#include <fstream>
#include "contactClass.h"
using namespace std;

bool isStringEmpty(string &name) {

    if (name.empty()) {
        cout << "Please enter a valid name:\n";
        return false;
    }

    return true;
}

void intBlackSpaceCheck(int &number) {

    // check for blank space in an integer
    while (!(cin >> number)) {

        cout << "Invalid input. Please try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void stringLength (int limit, string &name) {

    // set limit of string
    int charLimit = limit;

    if (name.length() >= charLimit) {
        cout << "The Character Limit is " << charLimit << "Please Try Again.\n";

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

void editContact() {}


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
        cin >> enterFirstName;
    } while (isStringEmpty(enterFirstName) == false);

    stringLength(3, enterFirstName);

    return enterFirstName;
}

string getLastName() {

    // ask for last name input
    string enterLastName;
    cout << "Enter contact last name (char limit: 20): ";
    cin >> enterLastName;

    isStringEmpty(enterLastName);
    stringLength(3, enterLastName);

    return enterLastName;
}

int getPhoneNumber() {

    // ask for phone number input
    int enterPhoneNumber;
    cout << "Enter contact phone number: ";
    cin >> enterPhoneNumber;

    intBlackSpaceCheck(enterPhoneNumber);

    return enterPhoneNumber;
}


Contact addContact() {

    Contact newContact = Contact(getFirstName(), getLastName(), getPhoneNumber());

    return newContact;
}