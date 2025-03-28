#ifndef __LIBRARY1_H__
#define __LIBRARY1_H__

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

bool checkIDOfStudents(const std::string &_ID);

bool checkNameOfStudents(const std::string &_name);

bool checkEmailOfStudents(const std::string &_email);

int checkNumberInput(int &number);

float checkNumberInput(float &number);

#endif // __LIBRARY1_H__