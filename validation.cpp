#include "validation.h"
#include <string>
#include <iostream>
using namespace std;

bool isStringEmpty(std::string &userInput) {

    // if the string is empty show error and return false else return true
    if (userInput.empty()) {
        return false;
    }
    return true;
}

void stringLength (int limit, std::string &userInput) {

    // set limit of string
    int charLimit = limit;

    if (userInput.length() >= charLimit) {
        // No More Printing In Validation Code
    }
}

bool checkInputIsInteger (int &userInput) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Please Enter a valid option to continue";
    }
    return true;
}