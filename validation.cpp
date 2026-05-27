#include "validation.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

bool isStringEmpty(std::string &userInput) {

    // if the string is empty show error and return false else return true
    if (userInput.empty()) {
        return false;
    }
    return true;
}

bool stringLength (int limit, std::string &userInput) {

    // set limit of string
    int charLimit = limit;

    if (userInput.length() > charLimit) {
        return false;
    }
    return true;
}

bool checkInputIsInteger (int &userInput) {
    while (!(cin >> userInput)) {
        cout << "Please enter a valid number: ";
        cin.clear();

        // maximum number of characters to ignore - \n character cin stops ignoring
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return true;
}