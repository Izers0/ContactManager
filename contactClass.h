#pragma once

#include <string>
#include <iostream>

class Contact {

    std::string FirstName;
    std::string LastName;
    std::string PhoneNumber;

public:
    // setters
    void setFirstName(std::string firstName) {
        FirstName = firstName;
    }
    void setLastName(std::string lastName) {
        LastName = lastName;
    }

    void setPhoneNumber(std::string phoneNumber) {
        PhoneNumber = phoneNumber;
    }

    // Getters
    std::string getFirstName() {
        return FirstName;
    }

    std::string getLastName() {
        return LastName;
    }

    std::string getPhoneNumber() {
        return PhoneNumber;
    }

    Contact(std::string firstName, std::string lastName, std::string phoneNumber) {
        FirstName = firstName;
        LastName = lastName;
        PhoneNumber = phoneNumber;
    }
};