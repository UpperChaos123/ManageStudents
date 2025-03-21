#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <gtest/gtest.h>

#include <string>

class Student
{
private:
    std::string m_ID;
    std::string m_name;
    int m_age;
    float m_GPA;

public:
    Student();
    Student(std::string _ID, std::string _name, int _age, float _GPA);
    ~Student();

    bool setID(std::string _ID);
    bool setName(std::string _name);
    bool setAge(int _age);
    bool setGPA(float _GPA);

    std::string getID() const;
    std::string getName() const;
    int getAge() const;
    float getGPA() const;

    bool inputInfo();
    void outputInfo() const;

    bool updateGPA(float newGPA);
};

#endif // __STUDENT_H__