#pragma once

#include "contactClass.h"

void stringBlankSpaceCheck();
void intBlankSpaceCheck();
void stringLength();

void writeContact();
void displayContacts();
void editContact();

void menu();

std::string getFirstName();
std::string getLastName();
int getPhoneNumber();

Contact addContact();