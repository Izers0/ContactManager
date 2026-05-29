#pragma once

#include <string>
#include <vector>

bool isStringEmpty(std::string &userInput);
bool checkStringLength(int limit, std::string &userInput);
bool checkInputIsInteger (int &userInput);
bool checkInputIsInRange (int &userInput, const std::vector<std::string> &contacts);