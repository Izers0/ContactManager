#include "validation.h"
#include <string>
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