#ifndef __MANAGESTUDENTS_H__
#define __MANAGESTUDENTS_H__

#include "class1/Student.h"
#include "library1.h"

#include <vector>
#include <memory>

void createListOfStudents(std::vector<std::unique_ptr<Student>> &students);

void displayListsOfStudents(const std::vector<std::unique_ptr<Student>> &students);

int findStudentsByID(const std::vector<std::unique_ptr<Student>> &students);

void removeStudentsByID(std::vector<std::unique_ptr<Student>> &students);

int findStudentsByName(const std::vector<std::unique_ptr<Student>> &students);

void findStudents(const std::vector<std::unique_ptr<Student>> &students);

void updateGPAOfStudents(std::vector<std::unique_ptr<Student>> &students);

#endif // __MANAGESTUDENTS_H__