#include <iostream>
#include <fstream>
#include "contactFunctionHeader.h"
using namespace std;

int main() {

    cout << "Contact Management\n";

    bool programRunning = true;

    while (programRunning == true) {

        int choice = 0;

        cout << "What do you want to do: \n\n";

        menu();

        cin >> choice;

        // Switch statement to take the users choice
        switch (choice) {
            case 1:
                displayContacts();
                break;
            case 2:
                writeContact();
                break;
            case 3:
                editContact();
                break;
            case 4:
                cout << "Goodbye";
                programRunning = false;
                break;
            default:
                cout << "Please Select 1-4\n";
        }
    }
}