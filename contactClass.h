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
    }
    void setLastName(std::string lastName) {

        LastName = lastName;
    }

    void setPhoneNumber(int phoneNumber) {

        PhoneNumber = phoneNumber;
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

    void displayInformation() {
        std::cout << "First Name: " << FirstName << std::endl;
        std::cout << "Last Name: " << LastName << std::endl;
        std::cout << "Phone Number: " << PhoneNumber << std::endl;
    }

    Contact(std::string firstName, std::string lastName, int phoneNumber) {

        FirstName = firstName;
        LastName = lastName;
        PhoneNumber = phoneNumber;
    }
};