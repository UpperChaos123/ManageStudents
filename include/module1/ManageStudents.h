#ifndef __MANAGESTUDENTS_H__
#define __MANAGESTUDENTS_H__

#include "class1/Student.h"
#include "library1.h"

#include <memory>

void addStudentsToList(std::vector<std::unique_ptr<Student>> &students);

void displayListOfStudents(const std::vector<std::unique_ptr<Student>> &students);

int findStudentsByID(const std::vector<std::unique_ptr<Student>> &students);

void removeStudentsByID(std::vector<std::unique_ptr<Student>> &students);

int findStudentsByName(const std::vector<std::unique_ptr<Student>> &students);

void findStudents(const std::vector<std::unique_ptr<Student>> &students);

void updateGPAOfStudents(std::vector<std::unique_ptr<Student>> &students);

void sortListOfStudents(std::vector<std::unique_ptr<Student>> &students);

#endif // __MANAGESTUDENTS_H__