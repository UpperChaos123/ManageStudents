#include "class1/Student.h"
#include "library1.h"

#include <algorithm>
#include <functional>

const std::vector<std::string> majors = {"Cong nghe thong tin", "Kinh te", "Ky thuat", "Y hoc", "Luat"};

Student::Student()
{
}

Student::Student(const std::string &_ID, const std::string &_name, const int &_age, const float &_GPA,
                 const std::string &_major, const std::string &_email, const std::string &_phone, const int &_credits)
{
    if (!validateAndSet(_ID, _name, _age, _GPA, _major, _email, _phone, _credits))
    {
        std::cerr << "Loi du lieu dau vao" << std::endl;
        std::cout << "\n";

        return;
    }
}

Student::~Student()
{
}

bool Student::setID(std::string &_ID)
{
    if (!checkIDOfStudents(_ID))
    {
        return false;
    }

    this->m_ID = _ID;
    return true;
}

bool Student::setName(std::string &_name)
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

bool Student::setAge(int &_age)
{
    if (_age < 18 || _age > 30)
    {
        std::cerr << "Do tuoi phai trong khoang tu 18 den 30" << std::endl;
        return false;
    }

    this->m_age = _age;
    return true;
}

bool Student::setGPA(float &_GPA)
{
    if (_GPA < 0.0 || _GPA > 4.0)
    {
        std::cerr << "Diem trung binh phai trong khoang tu 0.0 den 4.0" << std::endl;
        return false;
    }

    this->m_GPA = _GPA;
    return true;
}

bool Student::setMajor(std::string &_major)
{
    for (const auto &x : majors)
    {
        if (_major == x)
        {
            this->m_major = _major;
            return true;
        }
    }

    std::cerr << "Nganh hoc khong nam trong danh sach" << std::endl;
    return false;
}

bool Student::setEmail(std::string &_email)
{
    if (!checkEmailOfStudents(_email))
    {
        return false;
    }

    this->m_email = _email;
    return true;
}

bool Student::setPhone(std::string &_phone)
{
    if (!(_phone.length() == 10 && std::all_of(_phone.begin(), _phone.end(), [](char c)
                                               { return std::isdigit(static_cast<unsigned char>(c)); })))
    {
        std::cerr << "So dien thoai chi gom 10 chu so" << std::endl;
        return false;
    }

    this->m_phone = _phone;
    return true;
}

bool Student::setCredits(int &_credits)
{
    if (_credits < 0)
    {
        std::cerr << "So tin chi phai la so duong" << std::endl;
        return false;
    }

    this->m_credits = _credits;
    return true;
}

std::string Student::getID() const
{
    return this->m_ID;
}

std::string Student::getName() const
{
    return this->m_name;
}

int Student::getAge() const
{
    return this->m_age;
}

float Student::getGPA() const
{
    return this->m_GPA;
}

std::string Student::getMajor() const
{
    return this->m_major;
}

std::string Student::getEmail() const
{
    return this->m_email;
}

std::string Student::getPhone() const
{
    return this->m_phone;
}

int Student::getCredits() const
{
    return this->m_credits;
}

bool Student::validateAndSet(const std::string &_ID, const std::string &_name, const int &_age, const float &_GPA,
                             const std::string &_major, const std::string &_email, const std::string &_phone, const int &_credits)
{
    std::vector<std::function<bool()>> setters = {
        std::bind(&Student::setID, this, _ID),
        std::bind(&Student::setName, this, _name),
        std::bind(&Student::setAge, this, _age),
        std::bind(&Student::setGPA, this, _GPA),
        std::bind(&Student::setMajor, this, _major),
        std::bind(&Student::setEmail, this, _email),
        std::bind(&Student::setPhone, this, _phone),
        std::bind(&Student::setCredits, this, _credits)};

    for (const auto &setter : setters)
    {
        if (!setter())
        {
            return false;
        }
    }

    return true;
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
    int _age = checkNumberInput(_age);

    std::cout << "Nhap diem trung binh: ";
    float _GPA = checkNumberInput(_GPA);

    std::cout << "\n";
    std::cin.ignore();

    std::cout << "---Cac nganh hoc hien nay---" << std::endl;

    int i = 0;
    for (const auto &x : majors)
    {
        ++i;
        std::cout << std::to_string(i) + ". " + x << std::endl;
    }

    std::cout << "Nhap nganh hoc: ";
    std::string _major;
    std::getline(std::cin, _major);

    std::cout << "Nhap email: ";
    std::string _email;
    std::getline(std::cin, _email);

    std::cout << "Nhap so dien thoai: ";
    std::string _phone;
    std::getline(std::cin, _phone);

    std::cout << "Nhap so tin chi: ";
    int _credits = checkNumberInput(_credits);

    std::cout << "\n";
    std::cin.ignore();

    return validateAndSet(_ID, _name, _age, _GPA, _major, _email, _phone, _credits);
}

void Student::outputInfo() const
{
    std::cout << "Ma sinh vien: " << this->getID() << std::endl;
    std::cout << "Ten sinh vien: " << this->getName() << std::endl;
    std::cout << "Tuoi: " << this->getAge() << std::endl;
    std::cout << "Diem trung binh: " << this->getGPA() << std::endl;
    std::cout << "Hoc luc: " << this->getRank() << std::endl;
    std::cout << "Nganh hoc: " << this->getMajor() << std::endl;
    std::cout << "Email: " << this->getEmail() << std::endl;
    std::cout << "So dien thoai: " << this->getPhone() << std::endl;
    std::cout << "So tin chi: " << this->getCredits() << std::endl;
}

bool Student::updateGPA(float &newGPA)
{
    return this->setGPA(newGPA);
}

std::string Student::getRank() const
{
    if (this->getGPA() >= 3.6)
    {
        return "Xuat sac";
    }
    else if (this->getGPA() >= 3.2)
    {
        return "Gioi";
    }
    else if (this->getGPA() >= 2.5)
    {
        return "Kha";
    }
    else if (this->getGPA() >= 2.0)
    {
        return "Trung binh";
    }
    else
    {
        return "Yeu";
    }
}