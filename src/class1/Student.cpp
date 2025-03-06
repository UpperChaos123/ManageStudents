#include "class1/Student.h"
#include "library1.h"

#include <iostream>
#include <sstream>
#include <cctype>

Student::Student()
{
}

Student::Student(std::string ID, std::string name, int age, float GPA)
{
    if (!(this->setID(ID) && this->setName(name) && this->setAge(age) && this->setGPA(GPA)))
    {
        return;
    }
}

Student::~Student()
{
}

bool Student::setID(std::string ID)
{
    if (!checkIDOfStudents(ID))
    {
        return false;
    }

    this->ID = ID;
    return true;
}

bool Student::setName(std::string name)
{
    if (!checkNameOfStudents(name))
    {
        return false;
    }

    std::string str;
    std::stringstream ss(name);
    std::string k;

    while (getline(ss, k, ' '))
    {
        k[0] = toupper(k[0]);
        str = str + k + ' ';
    }
    str.pop_back();

    this->name = str;
    return true;
}

bool Student::setAge(int age)
{
    if (age < 18 || age > 30)
    {
        std::cout << "Do tuoi phai trong khoang tu 18 den 30" << std::endl;
        return false;
    }

    this->age = age;
    return true;
}

bool Student::setGPA(float GPA)
{
    if (GPA < 0.0 || GPA > 4.0)
    {
        std::cout << "Diem trung binh phai trong khoang tu 0.0 den 4.0" << std::endl;
        return false;
    }

    this->GPA = GPA;
    return true;
}

std::string Student::getID()
{
    return this->ID;
}

std::string Student::getName()
{
    return this->name;
}

int Student::getAge()
{
    return this->age;
}

float Student::getGPA()
{
    return this->GPA;
}

bool Student::inputInfo()
{
    std::cout << "Nhap ma sinh vien: ";
    std::string ID;
    std::getline(std::cin, ID);

    std::cout << "Nhap ten sinh vien: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Nhap do tuoi: ";
    int age;
    while (!(std::cin >> age))
    {
        std::cout << "Vui long nhap so nguyen: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cout << "Nhap diem trung binh: ";
    double GPA;
    while (!(std::cin >> GPA))
    {
        std::cout << "Vui long nhap so thuc: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cout << std::endl;

    if (!(this->setID(ID) && this->setName(name) && this->setAge(age) && this->setGPA(GPA)))
    {
        return false;
    }

    return true;
}

void Student::outputInfo()
{
    std::cout << "Ma sinh vien: " << this->getID() << std::endl;
    std::cout << "Ten sinh vien: " << this->getName() << std::endl;
    std::cout << "Tuoi: " << this->getAge() << std::endl;
    std::cout << "Diem trung binh: " << this->getGPA() << std::endl;
    std::cout << std::endl;
}

bool Student::updateGPA(float newGPA)
{
    return this->setGPA(newGPA);
}