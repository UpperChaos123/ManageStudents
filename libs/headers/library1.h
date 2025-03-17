#ifndef __LIBRARY1_H__
#define __LIBRARY1_H__

#include <string>
#include <iostream>
#include <sstream>

float convertStringToNumber(std::string str);

bool checkIDOfStudents(std::string _ID);

bool checkNameOfStudents(std::string _name);

int checkNumberInput(int &number);

float checkNumberInput(float &number);

#endif // __LIBRARY1_H__