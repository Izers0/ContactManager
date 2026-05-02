#include <iostream>
#include <fstream>
using namespace std;

class Contact {

    string FirstName;
    string LastName;
    string PhoneNumber;

public:
    // setters
    void setFirstName(string firstName) {

        FirstName = firstName;
    }
    void setLastName(string lastName) {

        LastName = lastName;
    }

    void setPhoneNumber(string phoneNumber) {

        PhoneNumber = phoneNumber;
    }

    // Getters
    string getFirstName() {
        return FirstName;
    }
    string getLastName() {
        return LastName;
    }
    string getPhoneNumber() {
        return PhoneNumber;
    }

    void displayInformation() {
        cout << "First Name: " << FirstName << endl;
        cout << "Last Name: " << LastName << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
    }

    Contact(string firstName, string lastName, string phoneNumber) {

        FirstName = firstName;
        LastName = lastName;
        PhoneNumber = phoneNumber;
    }
};

class WorkContacts : public Contact {

    string email;

    string getEmail() {

        return email;
    }
};

class FamilyFriendsContact : public Contact {

    string address;
    string dateOfBirth;
    bool isEmergencyContact = false;

    string getAddress() {
        return address;
    }
    string getDateOfBirth() {
        return dateOfBirth;
    }
};

void writeContact();
void displayContacts();
Contact addContact();

int main() {

    writeContact();
    displayContacts();

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

        while (contactFile.good()) {

            contactFile >> readFile;

            cout << readFile << "\n";
        }
    } else {
        cout << "Unable to open file when trying to display \n";
    }
}

Contact addContact() {

    // ask for first name input
    string enterFirstName;
    cout << "Enter contacts first name: ";
    cin >> enterFirstName;

    // ask for last name input
    string enterLastName;
    cout << "Enter contact last name: ";
    cin >> enterLastName;

    // ask for phone number input
    string enterPhoneNumber;
    cout << "Enter contact phone number: ";
    cin >> enterPhoneNumber;

   Contact newContact = Contact(enterFirstName, enterLastName, enterPhoneNumber);

   return newContact;
}