#ifndef __MANAGESTUDENTS_H__
#define __MANAGESTUDENTS_H__

#include "class1/Student.h"
#include "library1.h"

#include <memory>
#include <unordered_set>
#include <cstddef>

void addStudentsToList(std::vector<std::shared_ptr<Student>> &students,
                       std::unordered_set<std::string> &idSet,
                       std::unordered_set<std::string> &phoneSet,
                       std::unordered_set<std::string> &emailSet);

void displayListOfStudents(const std::vector<std::shared_ptr<Student>> &students);

void findStudentsByID(const std::vector<std::shared_ptr<Student>> &students);

void removeStudentsByID(std::vector<std::shared_ptr<Student>> &students);

void findStudentsByName(const std::vector<std::shared_ptr<Student>> &students);

void findStudentsByGPA(const std::vector<std::shared_ptr<Student>> &students);

void findStudents(const std::vector<std::shared_ptr<Student>> &students);

void updateGPAOfStudents(std::vector<std::shared_ptr<Student>> &students);

void sortListOfStudents(std::vector<std::shared_ptr<Student>> &students);

#endif // __MANAGESTUDENTS_H__