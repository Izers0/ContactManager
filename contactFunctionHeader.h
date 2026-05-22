#pragma once

#include "contactClass.h"

void writeContact();
void displayContacts();
void editContact();

void menu();

std::string getFirstName();
std::string getLastName();
std::string getPhoneNumber();

Contact addContact();