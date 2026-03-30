#include <iostream>
#include <fstream>
using namespace std;

class Contact {

    string firstName;
    string lastName;
    string phoneNumber;
};

class workContacts : public Contact {

    string email;
};

class familyFriendsContact : public Contact {

    string address;
    string dateOfBirth;
    bool isEmergencyContact = false;
};

void writeContact();

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
}