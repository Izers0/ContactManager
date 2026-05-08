#pragma once

#include <string>
#include <iostream>

class Contact {

    std::string FirstName;
    std::string LastName;
    int PhoneNumber;

public:
    // setters
    void setFirstName(std::string firstName) {

        FirstName = firstName;
        do {

            std::cout << "Enter contacts first name: ";

            getline(std::cin, firstName);
        } while (firstName.empty());
    }
    void setLastName(std::string lastName) {

        LastName = lastName;
        do {
            std::cout << "Enter contacts last name: ";

            getline(std::cin, lastName);
        } while (lastName.empty());
    }

    void setPhoneNumber(int phoneNumber) {

        PhoneNumber = phoneNumber;
        while (!(std::cin >> phoneNumber)) {

            std::cout << "Invalid input. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    // Getters
    std::string getFirstName() {
        return FirstName;
    }

    std::string getLastName() {
        return LastName;
    }

    int getPhoneNumber() {
        return PhoneNumber;
    }

    Contact(std::string firstName, std::string lastName, int phoneNumber) {

        FirstName = firstName;
        LastName = lastName;
        PhoneNumber = phoneNumber;
    }
};