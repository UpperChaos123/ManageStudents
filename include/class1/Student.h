#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>

class Student
{
private:
    std::string ID;
    std::string name;
    int age;
    float GPA;

public:
    Student();
    Student(std::string ID, std::string name, int age, float GPA);
    ~Student();

    bool setID(std::string ID);
    bool setName(std::string name);
    bool setAge(int age);
    bool setGPA(float GPA);

    std::string getID();
    std::string getName();
    int getAge();
    float getGPA();

    bool inputInfo();
    void outputInfo();

    bool updateGPA(float newGPA);
};

#endif // __STUDENT_H__