#include "class1/Student.h"
#include "library1.h"

Student::Student()
{
}

Student::Student(std::string _ID, std::string _name, int _age, float _GPA)
{
    if (!(this->setID(_ID) && this->setName(_name) && this->setAge(_age) && this->setGPA(_GPA)))
    {
        this->m_ID = "INVALID";
        this->m_name = "INVALID";
        this->m_age = -1;
        this->m_GPA = -1;

        return;
    }
}

Student::~Student()
{
}

bool Student::setID(std::string _ID)
{
    if (!checkIDOfStudents(_ID))
    {
        return false;
    }

    this->m_ID = _ID;
    return true;
}

bool Student::setName(std::string _name)
{
    if (!checkNameOfStudents(_name))
    {
        return false;
    }

    std::string str;
    std::stringstream ss(_name);
    std::string k;

    while (std::getline(ss, k, ' '))
    {
        k[0] = toupper(k[0]);
        str = str + k + ' ';
    }
    str.pop_back();

    this->m_name = str;
    return true;
}

bool Student::setAge(int _age)
{
    if (_age < 18 || _age > 30)
    {
        std::cerr << "Do tuoi phai trong khoang tu 18 den 30" << std::endl;
        return false;
    }

    this->m_age = _age;
    return true;
}

bool Student::setGPA(float _GPA)
{
    if (_GPA < 0.0 || _GPA > 4.0)
    {
        std::cerr << "Diem trung binh phai trong khoang tu 0.0 den 4.0" << std::endl;
        return false;
    }

    this->m_GPA = _GPA;
    return true;
}

std::string Student::getID()
{
    return this->m_ID;
}

std::string Student::getName()
{
    return this->m_name;
}

int Student::getAge()
{
    return this->m_age;
}

float Student::getGPA()
{
    return this->m_GPA;
}

bool Student::inputInfo()
{
    std::cout << "Nhap ma sinh vien: ";
    std::string _ID;
    std::getline(std::cin, _ID);

    std::cout << "Nhap ten sinh vien: ";
    std::string _name;
    std::getline(std::cin, _name);

    std::cout << "Nhap do tuoi: ";
    int _age = checkIntegerInput(_age);

    std::cout << "Nhap diem trung binh: ";
    float _GPA = checkFloatInput(_GPA);

    std::cout << "\n";

    if (!(this->setID(_ID) && this->setName(_name) && this->setAge(_age) && this->setGPA(_GPA)))
    {
        this->m_ID = "INVALID";
        this->m_name = "INVALID";
        this->m_age = -1;
        this->m_GPA = -1.0;

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
}

bool Student::updateGPA(float newGPA)
{
    return this->setGPA(newGPA);
}