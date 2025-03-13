#ifndef __LIBRARY1_H__
#define __LIBRARY1_H__

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

using std::string;
using std::cout;
using std::endl;

float convertStringToNumber(string str);

bool checkIDOfStudents(string _ID);

bool checkNameOfStudents(string _name);

#endif // __LIBRARY1_H__