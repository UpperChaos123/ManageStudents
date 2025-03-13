#include "class1/Student.h"
#include "library1.h"

Student::Student()
{
}

Student::Student(string _ID, string _name, int _age, float _GPA)
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

bool Student::setID(string _ID)
{
    if (!checkIDOfStudents(_ID))
    {
        return false;
    }

    this->m_ID = _ID;
    return true;
}

bool Student::setName(string _name)
{
    if (!checkNameOfStudents(_name))
    {
        return false;
    }

    string str;
    std::stringstream ss(_name);
    string k;

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
        cout << "Do tuoi phai trong khoang tu 18 den 30" << endl;
        return false;
    }

    this->m_age = _age;
    return true;
}

bool Student::setGPA(float _GPA)
{
    if (_GPA < 0.0 || _GPA > 4.0)
    {
        cout << "Diem trung binh phai trong khoang tu 0.0 den 4.0" << endl;
        return false;
    }

    this->m_GPA = _GPA;
    return true;
}

string Student::getID()
{
    return this->m_ID;
}

string Student::getName()
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
    cout << "Nhap ma sinh vien: ";
    string ID;
    std::getline(std::cin, ID);

    cout << "Nhap ten sinh vien: ";
    string name;
    std::getline(std::cin, name);

    cout << "Nhap do tuoi: ";
    int age;
    while (!(std::cin >> age))
    {
        cout << "Vui long nhap so nguyen: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    cout << "Nhap diem trung binh: ";
    double GPA;
    while (!(std::cin >> GPA))
    {
        cout << "Vui long nhap so thuc: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    cout << endl;

    if (!(this->setID(ID) && this->setName(name) && this->setAge(age) && this->setGPA(GPA)))
    {
        this->m_ID = "INVALID";
        this->m_name = "INVALID";
        this->m_age = -1;
        this->m_GPA = -1;
        
        return false;
    }

    return true;
}

void Student::outputInfo()
{
    cout << "Ma sinh vien: " << this->getID() << endl;
    cout << "Ten sinh vien: " << this->getName() << endl;
    cout << "Tuoi: " << this->getAge() << endl;
    cout << "Diem trung binh: " << this->getGPA() << endl;
}

bool Student::updateGPA(float newGPA)
{
    return this->setGPA(newGPA);
}