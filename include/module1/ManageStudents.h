#ifndef __MANAGESTUDENTS_H__
#define __MANAGESTUDENTS_H__

#include "class1/Student.h"

#include <vector>

using std::vector;

void createListOfStudents(vector<Student> &students);

void displayListsOfStudents(vector<Student> students);

void removeStudentsByID(vector<Student> &student);

int findStudentsByID(vector<Student> students);

int findStudentsByName(vector<Student> students);

void findStudents(vector<Student> students);

void updateGPAOfStudents(vector<Student> &students);

#endif // __MANAGESTUDENTS_H__