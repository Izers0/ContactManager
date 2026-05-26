#include <iostream>
#include <fstream>
#include "contactFunctionHeader.h"
#include "validation.h"
using namespace std;

int main() {

    cout << "Contact Management\n";

    bool programRunning = true;

    while (programRunning) {

        cout << "What do you want to do: \n\n";
        menu();

        int userInput;
        checkInputIsInteger(userInput);

        // Switch statement to take the users choice
        switch (userInput) {
            case 1:
                cin.ignore();
                displayContacts();
                break;
            case 2:
                cin.ignore();
                writeContact();
                break;
            case 3:
                cin.ignore();
                editContact();
                break;
            case 4:
                cin.ignore();
                deleteContact();
                break;
            case 5:
                cout << "Goodbye";
                programRunning = false;
                break;
            default:
                cout << "Please Select 1-5\n";
        }
    }
}