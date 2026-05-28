#include "contactFunctionHeader.h"
#include "validation.h"
#include "contactClass.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

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

        while (getline(contactFile, readFile)) {

            cout << readFile << "\n";
        }
    } else {
        cout << "Unable to open file when trying to display \n";
    }
}

void editContact() {

    ifstream readContactFile ("savedContacts.txt");

    vector <string> contacts;

    if (readContactFile.is_open()) {
        string readFile;

        // temporarily store each line in the file in a vector
        while (getline(readContactFile, readFile)) {
            contacts.push_back(readFile);
        }
        readContactFile.close();
    }

    cout << "Which Contact do you wish to edit: \n";

    // loop through contacts and give each a number (Display format for user)
    for (int i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". " << contacts[i] << "\n";
    }

    // user chooses the index of the contact they want to change
    int userInput;
    checkInputIsInteger(userInput);

    cin.ignore();

    cout << contacts[userInput - 1] << "\n";

    string userEdit;
    getline(cin, userEdit);

    // replace element in the vector with userEdit
    contacts[userInput - 1] = userEdit;

    /* Rewrite to file */
    ofstream rewriteContactFile ("savedContacts.txt");

    if (rewriteContactFile.is_open()) {

        for (int i = 0; i < contacts.size(); i++) {
            rewriteContactFile << contacts[i] << "\n";
        }
        rewriteContactFile.close();
    } else {
        cout << "Unable to open file \n";
    }
}

void deleteContact() {

    ifstream readContactFile ("savedContacts.txt");

    vector <string> contacts;

    if (readContactFile.is_open()) {
        string readFile;

        // temporarily store each line in the file in a vector
        while (getline(readContactFile, readFile)) {
            contacts.push_back(readFile);
        }
        readContactFile.close();
    }

    cout << "Which Contact do you wish to Delete: \n";

    // loop through contacts and give each a number
    for (int i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". " << contacts[i] << "\n";
    }

    // user chooses the index of the contact they want to delete
    int userInput;
    checkInputIsInteger(userInput);

    cin.ignore();

    cout << contacts[userInput - 1] << " has been deleted." << "\n";

    // delete element using the userInput
    contacts.erase(contacts.begin() + userInput - 1);


    /* Rewrite to file */
    ofstream rewriteContactFile ("savedContacts.txt");

    if (rewriteContactFile.is_open()) {

        for (int i = 0; i < contacts.size(); i++) {
            rewriteContactFile << contacts[i] << "\n";
        }
        rewriteContactFile.close();
    } else {
        cout << "Unable to open file \n";
    }
}


void menu() {

    cout << "1. View Contacts\n";
    cout << "2. Add a New Contact\n";
    cout << "3. Edit an Existing Contact\n";
    cout << "4. Delete a Existing Contact\n";
    cout << "5. Exit\n\n";
}


string getFirstName() {

    string enterFirstName;
    constexpr int characterLimit = 15;
    cout << "Enter the Contacts First Name (char limit 15): ";

    do {
        getline(cin, enterFirstName);

        if (isStringEmpty(enterFirstName) == false) {
            cout << "Enter the First Name (char limit 15) \n";
        }

        if (!checkStringLength(characterLimit, enterFirstName)) {
            cout << "First Name length is " << characterLimit << "\n";
        }

    } while (isStringEmpty(enterFirstName) == false || !checkStringLength(characterLimit, enterFirstName));

     return enterFirstName;
}

string getLastName() {

    string enterLastName;
    constexpr int characterLimit = 20;
    cout << "Enter the Contacts Last Name (char limit: 20): ";

    do {
        getline(cin, enterLastName);

        if (isStringEmpty(enterLastName) == false) {
            cout << "Enter the Last name (char limit 20) \n";
        }

        if (!checkStringLength(characterLimit, enterLastName)) {
            cout << "Last Name length is " << characterLimit << "\n";
        }

    } while (isStringEmpty(enterLastName) == false || !checkStringLength(characterLimit, enterLastName));

    return enterLastName;
}

string getPhoneNumber() {

    string enterPhoneNumber;
    constexpr int characterLimit = 11;
    cout << "Enter the Phone Number (char limit 11): ";

    do {
        getline(cin, enterPhoneNumber);

        if (isStringEmpty(enterPhoneNumber) == false) {
            cout << "Enter the Phone Number (char limit 11) \n";
        }

        if (!checkStringLength(characterLimit, enterPhoneNumber)) {
            cout << "Phone Number length is " << characterLimit << "\n";
        }

    } while (isStringEmpty(enterPhoneNumber) == false || !checkStringLength(characterLimit, enterPhoneNumber));

    return enterPhoneNumber;
}


Contact addContact() {

    Contact newContact = Contact(getFirstName(), getLastName(), getPhoneNumber());

    return newContact;
}