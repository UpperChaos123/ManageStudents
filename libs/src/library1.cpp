#include "library1.h"

#include <cctype>

float convertStringToNumber(std::string str)
{
    std::stringstream ss;
    ss << str;
    float x = 0;
    ss >> x;
    return x;
}

bool checkIDOfStudents(std::string _ID)
{
    if (_ID.empty())
    {
        std::cerr << "Ma sinh vien khong duoc de trong" << std::endl;
        return false;
    }

    if (_ID.length() != 8)
    {
        std::cerr << "Ma sinh vien phai co dung 8 ky tu" << std::endl;
        return false;
    }

    if (_ID.substr(0, 2) != "SV")
    {
        std::cerr << "Ma sinh vien phai bat dau bang SV" << std::endl;
        return false;
    }

    if (convertStringToNumber(_ID.substr(2)) < 1 || convertStringToNumber(_ID.substr(2)) > 999999)
    {
        std::cerr << "So thu tu cua ma sinh vien phai bat dau tu 000001 den 999999" << std::endl;
        return false;
    }

    return true;
}

bool checkNameOfStudents(std::string _name)
{
    if (_name.empty())
    {
        std::cerr << "Ten sinh vien khong duoc de trong" << std::endl;
        return false;
    }

    for (auto &x : _name)
    {
        if (!(isalpha(x) || x == ' '))
        {
            std::cerr << "Ten sinh vien chi chua chu cai va khoang trang" << std::endl;
            return false;
        }
    }

    return true;
}

int checkNumberInput(int &number)
{
    while(!(std::cin >> number)){
        std::cerr << "Vui long nhap so nguyen: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    return number;
}

float checkNumberInput(float &number)
{
    while(!(std::cin >> number)){
        std::cerr << "Vui long nhap so thuc: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    return number;
}