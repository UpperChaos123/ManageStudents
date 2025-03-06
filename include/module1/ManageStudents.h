#ifndef __MANAGESTUDENTS_H__
#define __MANAGESTUDENTS_H__

#include "class1/Student.h"

#include <vector>

void createListOfStudents(std::vector<Student> &students);

void displayListsOfStudents(std::vector<Student> students);

void removeStudentsByID(std::vector<Student> &student);

int findStudentsByID(std::vector<Student> students);

int findStudentsByName(std::vector<Student> students);

void findStudents(std::vector<Student> students);

void updateGPAOfStudents(std::vector<Student> &students);

#endif // __MANAGESTUDENTS_H__