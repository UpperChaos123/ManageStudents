#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>
#include <sstream>
#include <iostream>

#include <gtest/gtest.h>

using std::string;
using std::cin;
using std::istringstream;

class Student
{
private:
    string m_ID;
    string m_name;
    int m_age;
    float m_GPA;

public:
    Student();
    Student(string _ID, string _name, int _age, float _GPA);
    ~Student();

    bool setID(string _ID);
    bool setName(string _name);
    bool setAge(int _age);
    bool setGPA(float _GPA);

    string getID();
    string getName();
    int getAge();
    float getGPA();

    bool inputInfo();
    void outputInfo();

    bool updateGPA(float newGPA);
};

#endif // __STUDENT_H__