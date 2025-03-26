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
    std::string m_major;
    std::string m_email;
    std::string m_phone;
    int m_credits;

public:
    Student();
    Student(const std::string &_ID, const std::string &_name, const int &_age, const float &_GPA,
            const std::string &_major, const std::string &_email, const std::string &_phone, const int &_credits);
    ~Student();

    bool setID(std::string &_ID);
    bool setName(std::string &_name);
    bool setAge(int &_age);
    bool setGPA(float &_GPA);
    bool setMajor(std::string &_major);
    bool setEmail(std::string &_email);
    bool setPhone(std::string &_phone);
    bool setCredits(int &_credits);

    std::string getID() const;
    std::string getName() const;
    int getAge() const;
    float getGPA() const;
    std::string getMajor() const;
    std::string getEmail() const;
    std::string getPhone() const;
    int getCredits() const;

    bool validateAndSet(const std::string &_ID, const std::string &_name, const int &_age, const float &_GPA,
                        const std::string &_major, const std::string &_email, const std::string &_phone, const int &_credits);

    bool inputInfo();
    void outputInfo() const;

    bool updateGPA(float newGPA);
};

#endif // __STUDENT_H__