#include <iostream>
using namespace std;

class Contact {

    string firstName;
    string lastName;
    int phoneNumber;
};

class workContacts : public Contact {

    string email;

};

class familyFriendsContact : public Contact {

    string address;
    string dateOfBirth;
    bool isEmergencyContact = false;

};

int main() {



}