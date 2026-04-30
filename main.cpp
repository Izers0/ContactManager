#include <iostream>
#include <fstream>
using namespace std;

class Contact {

    string FirstName;
    string LastName;
    string PhoneNumber;

public:
    void setFirstName(string firstName) {

        FirstName = firstName;
    }
    void setLastName(string lastName) {

        LastName = lastName;
    }

    void setPhoneNumber(string phoneNumber) {

        PhoneNumber = phoneNumber;
    }

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
void addContact(Contact Firstname);

int main() {

    writeContact();

}

void writeContact() {

    ofstream contactFile;

    contactFile.open("savedContacts.txt", ios::app);

    if (contactFile.is_open()) {
        cout<< "Contact file successfully opened";
    } else {
        cout << "Unable to open file";
    }

    contactFile << "test";

    contactFile.close();
}

void addContact(Contact newContact) {

    string enterFirstName;
    cout << "Firstname: ";
    cin >> enterFirstName;

    string enterLastName;
    cout << "Lastname: ";
    cin >> enterLastName;

    string enterPhoneNumber;
    cout << "PhoneNumber: ";
    cin >> enterPhoneNumber;

    Contact newContact = (enterFirstName, enterLastName, enterPhoneNumber);
}